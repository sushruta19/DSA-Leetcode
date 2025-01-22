class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxIdx = 0
        for i in range(len(nums)):
            if maxIdx >= len(nums)-1:
                return True
            if i > maxIdx:
                return False
            maxIdx = max(maxIdx, i + nums[i])
        return False