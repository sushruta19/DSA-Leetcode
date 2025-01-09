class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        """so basically we m-1 down moves, n-1 right moves
        a permutation of these moves = number of unique paths
        we can reduce this problem to a combinatorial problem
        where we need to find no of unique strings have m-1 'D' and n-1 'R' letters
        ans = (m+n-2)!/((m-1)!(n-1)!) = C(m+n-2, min(m-1, n-1))
        min because we can exploit the properties of combination to reduce our
        multiplication operations
        """
        ans = 1
        k = min(m-1, n-1)
        for i in range(k):
            ans = (ans*(m+n-2-i))//(i+1)
        return ans
        # TC = O(min(m,n)) SC = O(1)