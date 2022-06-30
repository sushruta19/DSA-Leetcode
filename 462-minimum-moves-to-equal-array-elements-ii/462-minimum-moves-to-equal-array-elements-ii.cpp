class Solution {
public:
    int minMoves2(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(),nums.end());
      int midIndex = n/2;
      int moves = 0;
      
      for(int i=0; i<n; i++)
      {
        if(i!=midIndex)
        {
          moves+=abs(nums[midIndex]-nums[i]);
        }
      }
      return moves;
    }
};