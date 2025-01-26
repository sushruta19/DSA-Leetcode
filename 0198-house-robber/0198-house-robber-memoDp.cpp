class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        function <int(int)> f = [&](int i) -> int {
            if (i==0) return nums[i];
            if (i==-1) return 0;
            if (dp[i] != -1) return dp[i];

            dp[i] = max(nums[i] + f(i-2), 0 + f(i-1));
            return dp[i];
        };
        return f(n-1);
    }
};