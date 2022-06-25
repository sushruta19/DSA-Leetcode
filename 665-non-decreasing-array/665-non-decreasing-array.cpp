class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
      int n = nums.size();
      
      //storing the index where the ascending order broke
      //initialising to -1
      int index = -1;
      
      for(int i=0; i<n-1; i++)
      {
        //if order breaks
        if(nums[i]>nums[i+1])
        {
          //if order breaks for first time
          if(index == -1)
            //store the index where order broke
            index = i;
          else if(index != -1) //if order breaks for second time
            return false;
        }
      }
      //if order didn't break or it broke single time at the beginning or end
      if(index == -1 || index == 0 || index == n-2)
        return true;
      //There could be cases like {10,11,12,3,4,5}
      //Here, only one time the order breaks but number of elements to be changed is more than 1

      //{0,1,12,3,4,5}
      if(nums[index-1] <= nums[index+1])
        return true;
      //Or it could be {10,11,12,3,14,15}
      if(nums[index] <= nums[index+2])
        return true;

      return false;
    }
};