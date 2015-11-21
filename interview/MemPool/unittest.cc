/*
 * unittest uing GoogleTest
 */

#include "malloc.h"
#include "gtest/gtest.h"

// basic test
TEST(MemPool, Basic) {
  MemPool pool;
  ASSERT_EQ(100,pool.total_size());
  ASSERT_EQ(1,pool.class1_size());
  ASSERT_EQ(4,pool.class2_size());
  ASSERT_EQ(12,pool.class3_size());
}

TEST(MemPool, Malloc) {
  MemPool pool;
  EXPECT_EQ(0,pool.malloc(1));
  EXPECT_EQ(1,pool.malloc(4));
  EXPECT_EQ(5,pool.malloc(12));  
}

TEST(MemPool, Free) {
  MemPool pool;
  ASSERT_EQ(0,pool.malloc(1));
  pool.free(0);
  EXPECT_EQ(0,pool.malloc(4));
  pool.free(0);
  EXPECT_EQ(0,pool.malloc(12));
  pool.free(0);
}

TEST(MemPool, MallocFree){
  MemPool pool;
  EXPECT_EQ(0,pool.malloc(12));
  EXPECT_EQ(12,pool.malloc(12));
  EXPECT_EQ(24,pool.malloc(12));
  pool.free(12);
  EXPECT_EQ(12,pool.malloc(4));
  EXPECT_EQ(16,pool.malloc(1));
  EXPECT_EQ(36,pool.malloc(12));
}

TEST(MemPool, DrainPool) {
  MemPool pool;
  
  // first: drain
  EXPECT_EQ(0,pool.malloc(12));
  EXPECT_EQ(12,pool.malloc(12));
  EXPECT_EQ(24,pool.malloc(12));
  EXPECT_EQ(36,pool.malloc(12));
  EXPECT_EQ(48,pool.malloc(12));
  EXPECT_EQ(60,pool.malloc(12));
  EXPECT_EQ(72,pool.malloc(12));
  EXPECT_EQ(84,pool.malloc(12));
  EXPECT_EQ(100,pool.malloc(12)); // free space is not enough
  EXPECT_EQ(100,pool.malloc(12)); // free space is not enough
  EXPECT_EQ(100,pool.malloc(12)); // free space is not enough
  EXPECT_EQ(96,pool.malloc(4));   // now
  EXPECT_EQ(100,pool.malloc(1));  // no space at all
  
  // then free some
  pool.free(84);
  EXPECT_EQ(84,pool.malloc(4));   // now
  EXPECT_EQ(88,pool.malloc(4));   // now

  // Merge test
  pool.free(88);
  EXPECT_EQ(88,pool.malloc(4));   // now
  EXPECT_EQ(92,pool.malloc(4));   // now
  pool.free(92);
  pool.free(88);
  pool.free(84);

  EXPECT_EQ(84,pool.malloc(12));
  pool.free(84);
  
  EXPECT_EQ(84,pool.malloc(1));
  EXPECT_EQ(85,pool.malloc(1));
  EXPECT_EQ(86,pool.malloc(1));
  EXPECT_EQ(87,pool.malloc(1));
  pool.free(84);
  pool.free(85);
  pool.free(86);
  pool.free(87);
  EXPECT_EQ(84,pool.malloc(1));
  pool.free(84);
  EXPECT_EQ(84,pool.malloc(4));
}