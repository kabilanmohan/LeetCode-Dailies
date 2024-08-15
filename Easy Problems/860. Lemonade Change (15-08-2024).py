class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        if bills[0]!=5:
            return False
        fives_before,tens_before=0,0
        for i in bills:
            if i==5:
                fives_before+=1
            if i==10:
                if fives_before<1:
                    return False
                tens_before+=1
                fives_before-=1
            if i==20:
                if fives_before>=1 and tens_before>=1:
                    tens_before-=1
                    fives_before-=1
                elif fives_before>=3:
                    fives_before-=3
                else:
                    return False
        return True