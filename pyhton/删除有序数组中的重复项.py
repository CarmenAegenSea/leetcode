class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0 
        n = 1
        while n < len(nums):
            if nums[i] != nums[n]:
                i += 1
                nums[i] = nums[n]
            n += 1
        return i + 1