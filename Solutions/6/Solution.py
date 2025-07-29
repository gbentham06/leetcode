class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows <= 1 or len(s) <= numRows:
            return s
        
        rows = [""] * numRows
        point = 0
        direction = 1

        for i in s:
            rows[point] += i

            if point == 0:
                direction = 1
            elif point == numRows - 1:
                direction = -1

            point += direction

        return "".join(rows)