//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
         vector<vector<int>> res;
         sort(arr.begin(), arr.end());
         
         int n = arr.size();
         if(arr[n-1] < k/4) return res;
         
         for(int i=0; i<n-3; i++) {
             if(arr[i] > k/4) break;
             if(i>0 && arr[i-1] == arr[i]) continue;
             
             for(int j=i+1; j<n-2; j++) {
                 if(j>i+1 && arr[j-1] == arr[j]) continue;
                 int low = j+1, high = n-1;
                 while(low < high) {
                     long long sum = (long)arr[i] + (long)arr[j] + (long)arr[low] + (long)arr[high];
                     
                     if(sum > k) high--;
                     else if(sum < k) low++;
                     else {
                         res.push_back(vector<int>{arr[i], arr[j], arr[low], arr[high]});
                         int first_low_occurrence = arr[low], last_high_occurrence = arr[high];
                         while(low < high && arr[low] == first_low_occurrence) low++;
                         while(high > low && arr[high] == last_high_occurrence) high--;
                     }
                 }
             }
         }
         return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends