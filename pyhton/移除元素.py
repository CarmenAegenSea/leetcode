class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        num = 0

        for i in nums:
            if i != val:
                nums[num] = i
                num += 1
        
        return num
