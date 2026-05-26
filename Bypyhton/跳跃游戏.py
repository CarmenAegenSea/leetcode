from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxNumber = 0
        for i in range(len(nums)):
            if (i > maxNumber):
                return False
            maxNumber = max(maxNumber, i + nums[i])
        return True