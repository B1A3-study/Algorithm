class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_water = 0
        start, last = 0, len(height) - 1
        while start < last:
            if height[start] <= height[last]:
                max_water = max(max_water, height[start]*(last - start))
                start += 1
            else:
                max_water = max(max_water, height[last]*(last - start))
                last -= 1
        return max_water