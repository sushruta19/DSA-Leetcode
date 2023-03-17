//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  private:
    long long int merge(long long arr[], long long temp[], long long low, long long high) {
        long long mid = low + (high-low)/2;
        long long inv_count = 0;
        long long i = low;
        long long j = mid+1;
        long long k = low;
        while(i<=mid && j<=high) {
            if(arr[i] > arr[j]) {
                temp[k++] = arr[j++];
                inv_count += mid-i+1;
            }
            else temp[k++] = arr[i++];
        }
        while(i<=mid) temp[k++] = arr[i++];
        while(j<=high) temp[k++] = arr[j++];
        
        for(long long t=low; t<=high; t++) {
            arr[t] = temp[t];
        }
        
        return inv_count;
    }
    long long int mergeSort_count(long long arr[], long long temp[], long long low, long long high) {
        long long inversion_count = 0;
        if(low < high) {
            long long mid = low + (high-low)/2;
            inversion_count += mergeSort_count(arr, temp, low, mid);
            inversion_count += mergeSort_count(arr, temp, mid+1, high);
            inversion_count += merge(arr, temp, low, high);
        }
        return inversion_count;
    }
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        long long int inversionCount = mergeSort_count(arr, temp, 0, N-1);
        return inversionCount;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends