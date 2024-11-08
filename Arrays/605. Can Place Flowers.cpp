
    /*
    Time complexity : O(N)
    Space complexity : O(1)
    */


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size()<=1)
        {
            if(n == 0) return true;
            if(n==1 && flowerbed.size() == 1 && flowerbed[0] == 0) return true;
            return false;
        }
        int possible = 0;
        for(int i = 0 ; i < flowerbed.size() ; i++)
        {
            if(i == 0)
            {
                if(flowerbed[1] == 0 && flowerbed[0] == 0)
                {
                    possible++;
                    flowerbed[0] = 1;
                }
            }
            else if(i == flowerbed.size()-1)
            {
                if(flowerbed[i-1] == 0 && flowerbed[i] == 0)
                {
                    possible++;
                    flowerbed[i] = 1;
                }
            }
            else if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0 && flowerbed[i] == 0 )
            {
                possible++;
                flowerbed[i] = 1;
            }
        }
        if(possible >= n) return true;
        return false;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/can-place-flowers/
    */

    