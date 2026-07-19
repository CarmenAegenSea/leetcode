

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            i = int((left + right) / 2)
            if nums[i] < target:
                left = i + 1
            elif nums[i] > target:
                right = i - 1
            else:
                return i
        return -1