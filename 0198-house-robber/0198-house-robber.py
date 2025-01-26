class Solution:
    def rob(self, nums: List[int]) -> int:
        maxSum= -1
        n = len(nums)
        def func(i, curSum):
            if i >= n:
                nonlocal maxSum
                maxSum = max(maxSum, curSum)
                return
            curSum += nums[i]
            func(i+2, curSum)

            curSum -= nums[i]
            func(i+1, curSum)
        func(0, 0)
        return maxSum