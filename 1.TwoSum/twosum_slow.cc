//this version is two slow: time limit exceeded
//algorithm analysis: O(n^2)
class Solution
{
 public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    vector<int> indexs;
    typedef vector<int>::iterator item;

    for(item first=nums.begin(); first!=nums.end(); first++)
    {
      for(item second = first+1; second !=nums.end(); second++)
      {
        if(*first + *second == target)
        {
          indexs.push_back(first-nums.begin()+1);
          indexs.push_back(second-nums.begin()+1);
          return indexs;
        }
      }
    }
  }
};
