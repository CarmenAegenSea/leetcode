from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        if (len(nums) == 1): return 0
        changeNumber = 0
        maxNumber = 0
        for i in range(len(nums)):
            maxNumber = max(maxNumber, i + nums[i])
            changeNumber += 1
            if (maxNumber >= len(nums) - 1): 
                break
        return changeNumber
