class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> s;
      for(auto num : nums)
        s.insert(num);
      int count=1, maxCount=0, curr = 0;
      for(auto num: nums)
      {
        if(!(s.find(num-1)!=s.end()))
        {
          count = 1;
          curr = num;
          while(s.find(curr+1) != s.end())
          {
            count++;
            curr++;
          }
          maxCount = max(maxCount, count);
        }
      }
      return maxCount;
    }
};