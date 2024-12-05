
    /*
    Time complexity : O(n+m)
    Space complexity : O(1)
    */


class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int startIndex = 0, targetIndex = 0;

        while (startIndex < n || targetIndex < n) 
        {
            // Skip underscores
            while (startIndex < n && start[startIndex] == '_') 
            {
                startIndex++;
            }
            while (targetIndex < n && target[targetIndex] == '_')
             {
                targetIndex++;
            }

            // If one string is exhausted, both should be exhausted
            if (startIndex == n || targetIndex == n) 
            {
                return startIndex == n && targetIndex == n;
            }

            // Check if the pieces match and follow movement rules
            if (start[startIndex] != target[targetIndex] ||
                (start[startIndex] == 'L' && startIndex < targetIndex) ||
                (start[startIndex] == 'R' && startIndex > targetIndex))
                return false;

            startIndex++;
            targetIndex++;
        }

        //all conditions are satisfied
        return true;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/move-pieces-to-obtain-a-string/
    */

    