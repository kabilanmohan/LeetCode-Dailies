
    /*
    Time complexity : O(max(n,m))
    Space complexity : O(1)
    */


class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) 
    {
        int i = 0 , j = 0 ;
        while(i < str1.size() && j < str2.size())
        {
            if(str1[i] == str2[j])
            {
                i++;
                j++;
            }
            else
            {
                if(str1[i] =='z')
                {
                    if(str2[j] == 'a')
                    {
                        i++;
                        j++;
                    }
                    else i++;
                }

                else
                {
                    if((str1[i]+1) == str2[j])
                    {
                        i++;
                        j++;
                    }
                    else i++;
                }
            }
        }

        if(j == str2.size()) return true;
        return false;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/
    */

    