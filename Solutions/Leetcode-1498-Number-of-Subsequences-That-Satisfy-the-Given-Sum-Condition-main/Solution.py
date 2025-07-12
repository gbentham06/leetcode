class Solution:
    def numSubseq(self, nums: list[int], target: int) -> int:
        MOD = 10**9 + 7
        nums.sort()
        n = len(nums)
        
        # Powers
        pows = [1] * n
        for i in range(1, n):
            pows[i] = (pows[i-1] * 2) % MOD
            
        count, left, right = 0,0,n-1
        
        # 2 pointer solution
        while left <= right:
            if nums[left] + nums[right] <= target:
                count = (count + pows[right - left]) % MOD
                left += 1
            else:
                right -= 1
                
        return count
