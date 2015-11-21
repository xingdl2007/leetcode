/*
  * a simple class which implement MemPool
  */
#include <stdexcept>
#include "malloc.h"

// little ugly, disobey DRY
uint32_t MemPool::malloc(uint32_t size) {
  uint32_t base_addr = total_size_;
  if(size == class1_size_) {
    // when empty, load several
    if(free_fifo1.empty()) load_fifo(size);
    
    if(!free_fifo1.empty()) {
      base_addr = free_fifo1.front();
      free_fifo1.pop_front();
      used_set1.insert(base_addr);
    } 
  }else if(size == class2_size_) {
    // when empty, load several
    if(free_fifo2.empty()) load_fifo(size);
    
    if(!free_fifo2.empty()) {
      base_addr = free_fifo2.front();
      free_fifo2.pop_front();
      used_set2.insert(base_addr);
    } 
  }else if(size == class3_size_) {
    // when empty, load several
    if(free_fifo3.empty()) load_fifo(size);
    
    if(!free_fifo3.empty()) {
      base_addr = free_fifo3.front();
      free_fifo3.pop_front();
      used_set3.insert(base_addr);
    } 
  }
  else {
    throw std::runtime_error("invalid size");
  }
  return base_addr;
}

// little ugly, disobey DRY
void MemPool::free(uint32_t ptr) {
  std::set<uint32_t>::iterator it;
  if((it = used_set1.find(ptr)) != used_set1.end()){
    used_set1.erase(it);
    free_space[ptr] = class1_size_;
  }else if((it = used_set2.find(ptr)) != used_set2.end()){
    used_set2.erase(it);
    free_space[ptr] = class2_size_;
  }else if((it = used_set3.find(ptr)) != used_set3.end()){
    used_set3.erase(it);
    free_space[ptr] = class3_size_;
  }else
    throw std::runtime_error("invalid ptr for free");
}

// little ugly, disobey DRY
void MemPool::load_fifo(uint32_t size) {
  uint32_t base_addr;
  
  // first call merge
  merge();
  
  if(size == class1_size_) {
    if(free_fifo1.size() >= waterline) return;
    while(free_fifo1.size() < waterline) {
      base_addr = scan(size);
      if(base_addr == total_size_) break;
      free_fifo1.push_back(base_addr);
    }
  }else if(size == class2_size_) {
    if(free_fifo2.size() >= waterline) return;
    while(free_fifo2.size() < waterline) {
      base_addr = scan(size);
      if(base_addr == total_size_) break;
      free_fifo2.push_back(base_addr);
    }
  }else if(size == class3_size_) {
    if(free_fifo3.size() >= waterline) return;
    while(free_fifo3.size() < waterline) {
      base_addr = scan(size);
      if(base_addr == total_size_) break;
      free_fifo3.push_back(base_addr);
    }
  }else
    throw std::runtime_error("invalid size");    
}

// find a vliad free size space and return the base addr
// return the base_addr if find, TOTAL_SIZE otherwise
uint32_t MemPool::scan(uint32_t size) {
  mem_it it = free_space.begin();
  uint32_t ret=total_size_, sz, base_addr;
  for(; it != free_space.end(); ++it) {
    if(it->second >= size) {
      ret = it->first;
      base_addr = it->first + size;
      sz = it->second - size;
      free_space.erase(it);
      free_space[base_addr] = sz;
      break;
    }
  }
 return ret; 
}

// find all adjecent free block and merge them
void MemPool::merge() {
  mem_it it = free_space.begin(), it_adj;
  uint32_t adjecent;
  while(it != free_space.end()) {
    adjecent = it->first + it->second;
    
    if((it_adj = free_space.find(adjecent)) != free_space.end()) {
      free_space[it->first] = it->second + it_adj->second;
      // erase: only it_adj invalid
      free_space.erase(it_adj);
    }else {
      it++;
    }
  }
}