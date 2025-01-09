class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # dp = [[1]*n for _ in range(m)]
        """state transition equation is
        dp[i][j] = dp[i-1][j] + dp[i][j-1] for i, j > 0
        But since we are taking only the previous row and col value
        we can optimize our space  
        """
        dp = [1]*n
        for i in range(1, m):
            for j in range(1, n):
                dp[j] = dp[j] + dp[j-1] 
        return dp[-1]
