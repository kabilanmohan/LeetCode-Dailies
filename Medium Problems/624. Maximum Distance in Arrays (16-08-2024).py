class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        minele, maxele = arrays[0][0], arrays[0][-1]
        max_distance = 0
        
        for i in arrays[1:]:
            last = len(i) - 1
            max_distance = max(max_distance, abs(maxele - i[0]), abs(i[last] - minele))
            if i[0] < minele:
                minele = i[0]
            if i[last] > maxele:
                maxele = i[last]
        
        return max_distance
            
