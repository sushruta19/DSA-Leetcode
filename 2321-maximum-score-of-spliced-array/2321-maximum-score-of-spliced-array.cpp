class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
      int n = nums1.size();
      
      int sum1 = 0;
      for(auto x : nums1)
        sum1 += x;
      
      int sum2 = 0;
      for(auto x : nums2)
        sum2 += x;
      
      int maxScore = max(sum1, sum2);
      
      int subarrayDiff1 = 0, subarrayDiff2 = 0, maxDiff1 = 0, maxDiff2 = 0;
      for(int i=0; i<n; i++)
      {
        subarrayDiff1 += nums2[i] - nums1[i];
        subarrayDiff2 += nums1[i] - nums2[i];
        
        maxDiff1 = max(maxDiff1, subarrayDiff1);
        maxDiff2 = max(maxDiff2, subarrayDiff2);
        
        if(subarrayDiff1 < 0)
          subarrayDiff1 = 0;
        if(subarrayDiff2 < 0)
          subarrayDiff2 = 0;
      }
      maxScore = max(maxScore , max(sum1+maxDiff1, sum2+maxDiff2));
      return maxScore;
    }
};