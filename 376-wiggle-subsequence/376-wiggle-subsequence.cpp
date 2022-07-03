class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
      int n = nums.size();
      if(n==1)
        return 1;
      vector<char> diff;
      diff.reserve(nums.size()-1);
      for(int i=1; i<n; i++)
      {
        char ch = '0';
        if(nums[i]-nums[i-1]>0)
          ch = '+';
        else if(nums[i]-nums[i-1]<0)
          ch = '-';
        diff.push_back(ch);
      }
      int counter = 0;
      char prev = '0';
      for(int i=0; i< diff.size(); i++)
      {
        if(prev == '0' && diff[i] != '0')
        {
          counter++;
          prev = diff[i];
        }
        else if(prev == '+' && diff[i] == '-')
        {
          counter++;
          prev = diff[i];
        }
        else if(prev == '-' && diff[i] == '+')
        {
          counter++;
          prev = diff[i];
        }
      }
      return counter+1;
    }
};