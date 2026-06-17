class Solution:
    def maxArea(self, height: list[int]) -> int:
        left, right = 0, len(height) - 1
        maxV = 0
        while left < right:
            h = height[left] if height[left] < height[right] else height[right]
            w = right - left
            v = h * w
            if v > maxV:
                maxV = v
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return maxV
