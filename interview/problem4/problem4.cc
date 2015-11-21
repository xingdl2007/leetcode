/*
 * sword to offer: problem 4
 * O(N)
 * replace:
 *         input:  "We are happy."
 *         output: "We%20are%20happy."
 * len: the total len of str
 */
#include <stdint.h>
#include <string.h>

#include "gtest/gtest.h"

void replace(char *str, int len) {
  if(str == NULL || len < 0) return;
  
  uint32_t i=0, blank =0, totallen;
  while(str[i] != '\0') {
    if(str[i] == ' ') blank++;
    i++;
  }
  // two extra char per blank
  i = strlen(str) + 1;
  totallen = i + 2*blank;
  if(totallen > len) return;

  // including the copy of '\0'
  while(i) {
    if(str[i] == ' ') {
      str[totallen--] = '0';
      str[totallen--] = '2';
      str[totallen--] = '%';
    }else str[totallen--] = str[i];
    i--;
  }
}


TEST(REPLACE,BASIC) {
  char str[100] = {"We are happy."};
  replace(str,100);
  ASSERT_STREQ("We%20are%20happy.",str);
}
