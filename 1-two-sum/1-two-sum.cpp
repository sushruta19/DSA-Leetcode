class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> ans;
      unordered_map <int, int> m;
      for(int i=0; i<nums.size(); i++)
      {
        int temp = target - nums[i];
        if(m.find(temp)!=m.end())
        {
          ans.push_back(m[temp]);
          ans.push_back(i);
          break;
        }
        m[nums[i]] = i;
      }
      return ans;
    }
};