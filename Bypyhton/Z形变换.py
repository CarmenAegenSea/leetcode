

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2 or len(s) <= numRows:
            return s

        rows = [[] for _ in range(numRows)]

        row = 0      
        direction = 1  

        for ch in s:
            rows[row].append(ch)

            if row == 0:
                direction = 1
            elif row == numRows - 1:
                direction = -1
            row += direction

        return ''.join(''.join(row) for row in rows)
    