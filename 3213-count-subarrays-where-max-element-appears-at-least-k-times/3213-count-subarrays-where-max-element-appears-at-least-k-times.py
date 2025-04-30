class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        max_indices = []
        max_num = -1 
        for i, num in enumerate(nums):
            if num > max_num:
                max_num = num
                max_indices.clear()
                max_indices.append(i)
            elif num == max_num:
                max_indices.append(i)
        
        if len(max_indices) < k:
            return 0
        cnt = 0
        n = len(nums)
        start_i = -1
        for j in range(len(max_indices)-k+1):
            cnt += (max_indices[j]-start_i)*(n-max_indices[j+k-1])
            start_i = max_indices[j]
        return cnt