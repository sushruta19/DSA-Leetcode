//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        int target = 0;
        vector<int> prefixSum;
        prefixSum.reserve(n);
        prefixSum.push_back(arr[0]);
        for(int i=1; i<n; i++) prefixSum.push_back(arr[i] + prefixSum[i-1]);
        
        unordered_map<int, int> hashMap;
        int length = 0, max_length = 0;
        for(int i=0; i<n; i++) {
            if(prefixSum[i] == target) {
                length = i+1;
                max_length = max(max_length, length);
            }
            else if(hashMap.find(prefixSum[i] - target) != hashMap.end()) {
                 int j = hashMap[prefixSum[i]-target];
                 //[j+1 .. i]
                 length = i-j;
                 max_length = max(max_length, length);
            }
            
            if(hashMap.find(prefixSum[i]) == hashMap.end()) hashMap[prefixSum[i]] = i;
        }
        return max_length;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends