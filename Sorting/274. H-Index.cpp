
    /*
    Time complexity : O(nlogn)
    Space complexity : O(1)
    */


class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int size = citations.size();
        for (int j = 0; j < size; j++) {
            int h = size - j;
            if (citations[j] >= h) {
                return h;
            }
        }
        return 0;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/h-index/?envType=study-plan-v2&envId=top-interview-150
    */

    