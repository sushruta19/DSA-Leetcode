//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int rows = n;
    int cols = m;
    int count = 0, max_count = 0, max_row = -1;
    int j=cols-1, i=0;
    while(j>=0 && i<rows) {
        if(arr[i][j] == 1) {
            count++;
            j--;
            if(count > max_count) {
                max_row = i;
                max_count = count;
            }
        }
        else {
            i++;
        }
    }
    return max_row;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends