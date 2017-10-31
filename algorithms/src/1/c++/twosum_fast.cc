//hashmap solution ref Hao chen

class Solution
{
 public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    map<int, int> m;
    vector<int> indexs;

    for(int i=0; i<nums.size(); ++i)
    {
      if(m.find(nums[i]) == m.end()){
        m[target-nums[i]] = i;
      }else{
        indexs.push_back(m[nums[i]] + 1);
        indexs.push_back(i+1);
        return indexs;
      }
    }
  }
};
