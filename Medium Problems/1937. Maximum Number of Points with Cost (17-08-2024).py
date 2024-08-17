class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        rows, cols = len(points), len(points[0])
        
        dp = points[0][:]  
        
        left_max = [0] * cols  
        right_max = [0] * cols 
        
        for r in range(1, rows):
            for c in range(cols):
                if c == 0:
                    left_max[c] = dp[c]
                else:
                    left_max[c] = max(left_max[c - 1] - 1, dp[c])
            
            for c in range(cols - 1, -1, -1):
                if c == cols - 1:
                    right_max[c] = dp[c]
                else:
                    right_max[c] = max(right_max[c + 1] - 1, dp[c])
                    
            for c in range(cols):
                dp[c] = points[r][c] + max(left_max[c], right_max[c])
                
        return max(dp)
