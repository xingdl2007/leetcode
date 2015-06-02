//simple unit test
using namespace std;
#include <map>
#include <vector>
#include <iostream>
//#include "twosum_slow.cc"
#include "twosum_fast.cc"

void vector_dump(vector<int>& input)
{
  for(vector<int>::iterator item=input.begin(); item != input.end(); item++)
    cout << *item << " ";

  cout<<endl;
}

int main(int argc, char*argv[])
{
  int numbers[] = {2,7,11,15};
  int target = 9;
  
  vector<int> nums(numbers,numbers+sizeof(numbers)/sizeof(int));
  vector<int> indexs = (new Solution())->twoSum(nums,target);

  vector_dump(nums);
  vector_dump(indexs);
}
