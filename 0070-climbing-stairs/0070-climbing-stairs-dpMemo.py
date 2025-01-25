class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [-1]*(n+1)
        # DP Memoization
        def climb(n):
            if n <= 1:
                return 1
            if dp[n] != -1:
                return dp[n]
            dp[n] = climb(n-1) + climb(n-2)
            return dp[n]
        return climb(n)
        