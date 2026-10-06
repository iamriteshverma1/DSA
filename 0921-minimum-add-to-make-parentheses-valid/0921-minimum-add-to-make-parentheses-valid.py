class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        totalOpen = 0
        totalClose = 0

        for c in s:
            if c == '(':
                totalOpen += 1
            else:
                if totalOpen:
                    totalOpen -= 1
                    totalClose -= 1
                
                totalClose += 1
        return totalClose + totalOpen