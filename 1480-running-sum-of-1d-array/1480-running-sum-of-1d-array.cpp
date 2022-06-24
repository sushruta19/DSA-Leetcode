class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
      vector<int> prefix;
      prefix.reserve(nums.size());
      prefix.push_back(nums[0]);
      for(int i=1;i<nums.size();i++)
      {
        prefix.push_back(nums[i]+prefix[i-1]);
      }
      return prefix;
    }
};