class Solution:
    def largestGoodInteger(self, num: str) -> str:
        return max(
            (num[i] * 3 for i in range(2, len(num)) if num[i] == num[i-1] == num[i-2]),
            default=""
        )
