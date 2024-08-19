class Solution:
    def minSteps(self, n: int) -> int:
        if n == 1:
            return 0
        
        number = 2
        result = 0
        
        while n > 1:
            while n % number == 0:
                result += number
                n //= number
            number += 1
            
        return result