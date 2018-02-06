//simple unit test
#include <map>
#include <vector>
#include <iostream>

using namespace std;

//hashmap solution ref Hao chen
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> m;
    vector<int> indexs;

    for (int i = 0; i < nums.size(); ++i) {
      if (m.find(nums[i]) == m.end()) {
        m[target - nums[i]] = i;
      } else {
        indexs.push_back(m[nums[i]] + 1);
        indexs.push_back(i + 1);
        return indexs;
      }
    }
  }
};

void vector_dump(vector<int> &input) {
  for (vector<int>::iterator item = input.begin(); item != input.end(); item++)
    cout << *item << " ";

  cout << endl;
}

int main(int argc, char *argv[]) {
  int numbers[] = {2, 7, 11, 15};
  int target = 9;

  vector<int> nums(numbers, numbers + sizeof(numbers)/sizeof(int));
  vector<int> indexs = (new Solution())->twoSum(nums, target);

  vector_dump(nums);
  vector_dump(indexs);
}
