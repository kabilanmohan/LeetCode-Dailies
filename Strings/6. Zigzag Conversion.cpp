
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> zigzag(numRows , ""); // each string represent each row
        int col = 0 , row = -1 , i = 0;
        while(i < s.size())
        {
            // go down
            while(i < s.size() && row < numRows - 1)
            {
                row++;
                zigzag[row] += s[i];
                i++;
            }

            // go diagonally up
            while(i < s.size() && row >0 && col < s.size())
            {
                col++;
                row--;
                zigzag[row] += s[i];
                i++;
            }
        }

        string result = "";
        for(auto x: zigzag)
        {
            result+= x;
        }
        return  result;
    }
    
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/zigzag-conversion/
    */

    