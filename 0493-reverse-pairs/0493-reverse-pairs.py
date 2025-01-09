class Solution:
    def merge_count(self, nums, low, mid, high):
        cnt = 0
        left = nums[low:mid+1]
        right = nums[mid+1:high+1]
        j = 0
        for i in range(len(left)):
            while j < len(right) and left[i] > 2*right[j]:
                j += 1
            cnt += j
        i, j, k = 0, 0, low
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                nums[k] = left[i]
                i += 1
            else:
                nums[k] = right[j]
                j += 1
            k += 1
        while i < len(left):
            nums[k] = left[i]
            k += 1
            i += 1
        while j < len(right):
            nums[k] = right[j]
            k += 1
            j += 1
        return cnt

    def merge_sort_count(self, nums, low, high):
        if low < high:
            cnt = 0
            mid = low + (high-low)//2
            cnt += self.merge_sort_count(nums, low, mid)
            cnt += self.merge_sort_count(nums, mid+1, high)
            cnt += self.merge_count(nums, low, mid, high)
            return cnt
        return 0
    def reversePairs(self, nums: List[int]) -> int:
        return self.merge_sort_count(nums, 0, len(nums)-1)