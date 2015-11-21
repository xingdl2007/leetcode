/*
 * a simple class which implement MemPool
 */
#include <deque>
#include <set>
#include <map>
#include <stdint.h>

class MemPool {
 public:
  MemPool(uint32_t total_size=100, uint32_t class1_size=1,
          uint32_t class2_size=4, uint32_t class3_size=12)
      :total_size_(total_size), class1_size_(class1_size),
      class2_size_(class2_size),class3_size_(class3_size)
  {
    free_space[0] = total_size;
  };
  
  // malloc a size memory_space, return the base addr
  // if no free sapce, return the total_size;
  // which is a invalid address
  uint32_t malloc(uint32_t size);
  // free the malloced addr
  void free(uint32_t ptr);

  // return total size
  uint32_t total_size()  const { return total_size_; }
  uint32_t class1_size() const { return class1_size_;}
  uint32_t class2_size() const { return class2_size_;}
  uint32_t class3_size() const { return class3_size_;}
  
 private:
  // can change this value after test
  static const uint32_t waterline = 1;

  // load free_fifo
  void load_fifo(uint32_t size);
  
  // scan the free_space map, merge free blocks
  void merge();

  // scan the free_space map, find a valid free block
  uint32_t scan(uint32_t size);
 
  uint32_t total_size_;

  // only support three fixed size-class block
  uint32_t class1_size_;
  uint32_t class2_size_;
  uint32_t class3_size_;

  // each size will have a free_fifo
  std::deque<uint32_t> free_fifo1, free_fifo2, free_fifo3;
  // each size will have a malloced_set to record the addr
  std::set<uint32_t> used_set1, used_set2, used_set3;

  typedef std::map<uint32_t, uint32_t>::iterator mem_it;
  // a map used to maintain all empty mem-space
  // first: base addr(actally the index), second: size
  std::map<uint32_t,uint32_t> free_space;
};