class Solution:
    def trap(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        lMax = height[l]
        rMax = height[r]
        trappedWater = 0
        while l < r:
            if lMax < rMax:
                l += 1
                lMax = max(lMax, height[l])
                trappedWater += lMax - height[l]
            
            else:
                r -= 1
                rMax = max(rMax, height[r])
                trappedWater += rMax - height[r]
        return trappedWater
