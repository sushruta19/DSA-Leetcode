//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int ans_xor = 0;
        for(int num = 1; num<=n; num++) ans_xor ^= num;
        for(int i=0; i<n; i++) ans_xor ^= arr[i];
        
        int mask = ans_xor&~(ans_xor-1);
        
        int a = 0;
        int b = 0;
        for(int num = 1; num<=n; num++) {
            if(mask&num) a ^= num;
            else b ^= num;
        }
        for(int i=0; i<n; i++) {
            if(mask&arr[i]) a^= arr[i];
            else b^= arr[i];
        }
        bool is_a_missing = true;
        for(int i=0; i<n; i++) {
            if(arr[i] == a) {
                is_a_missing = false;
                break;
            }
        }
        int *ans = new int[2];
        ans[0] = a, ans[1] = b;
        if(is_a_missing) 
            ans[0] = b, ans[1] = a;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends