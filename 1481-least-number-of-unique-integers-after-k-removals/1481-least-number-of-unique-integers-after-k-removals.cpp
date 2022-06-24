class Solution {
public:
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
      //sort the array
      sort(arr.begin(),arr.end());
      int n = arr.size();
      
      //array to store only freq values and not the keys
      int freq[100000]={0};
      int prev = arr[0], count=0;
      freq[count]++;
      for(int i=1; i<n; i++)    //storing only the freq values
      {
        if(arr[i] == prev)
          freq[count]++;
        else
        {
          count++;
          freq[count]++;
        }
        prev = arr[i];
      }
      
      sort(freq, freq+count+1); //sorting the freq values
      
      int remove=0;             //to track the distinct numbers to be removed
      for(int i=0; i<=count;i++)
      {
        if(k>=freq[i])
        {
          remove++;
          k-=freq[i];
        }
      }
      return count+1 - remove;
    }
};