class Solution:
    def reverse(self, x: int) -> int:
        sign = -1 if x < 0 else 1
        out = 0
        x = abs(x)
        
        while x > 0:
            num = x % 10
            x //= 10
            out = (out * 10) + num

        if out > (2**31) - 1:
            return 0
            
        return out * sign
