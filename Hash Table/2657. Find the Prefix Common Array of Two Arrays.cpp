
    /*
    Time complexity : O(N)
    Space complexity : O(N)
    */


class Solution {
public:

    int count_freq_equal(vector<int>& a , vector<int>& b, int n)
    {
        int count = 0;
        for(int i = 0 ; i < n ; i++) if(a[i] == b[i] && a[i] != 0) count++;
        return count;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        const int n = A.size();
        vector<int> result(n , 0) , freqa(n , 0) , freqb(n , 0);

        for(int i = 0 ; i < n ; i++)
        {
            freqa[A[i]-1] += 1;
            freqb[B[i]-1] += 1;

            result[i] = count_freq_equal(freqa,freqb,n);
        }
        return result;
    }


};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
    */

    