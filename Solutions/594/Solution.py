class Solution:
    def findLHS(self, nums: List[int]) -> int:
        nums.sort()
        lp, out, n = 0, 0, len(nums)
        for rp in range(n):
            while nums[rp] - nums[lp] > 1:
                lp += 1
            if nums[rp] - nums[lp] == 1:
                out = max(out, rp-lp+1)
        return out
