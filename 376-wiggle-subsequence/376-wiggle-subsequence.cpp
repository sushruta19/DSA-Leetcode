class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
      int n = nums.size();
      if(n==1)
        return 1;
      vector<int> diff;
      diff.reserve(n-1);
      for(int i=1; i<n; i++)
      {
        int sign = 0;
        if(nums[i]-nums[i-1]>0)
          sign = 1;
        else if(nums[i]-nums[i-1]<0)
          sign = -1;
        diff.push_back(sign);
      }
      
      int counter = 0, prev = 0;
      for(int i=0; i< diff.size(); i++)
      {
        int curr = diff[i];
        if(prev == 0 && curr!= 0)
        {
          counter++;
          prev = curr;
        }
        else if(prev*curr<0)
        {
          counter++;
          prev = curr;
        }
      }
      return counter+1;
    }
};