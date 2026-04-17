class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return len(nums)

        n = 2
        i = 2
        while i < len(nums):
            if nums[n - 2] != nums[i]:
                nums[n] = nums[i]
                n += 1
            i += 1
        
        return n