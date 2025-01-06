
    /*
    Time complexity : O(nlogn)
    Space complexity : O(1)
    */


class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(),answers.end());
        int n = answers.size();
        int ans = 0;

        int i=0;
        while(i<n){
            int prev = answers[i];
            ans+=answers[i]+1;
            int j =0;
            while(j<=prev && i+j<n && answers[i+j]==prev){
                j++;
            }
            i+=j;
        }
        return ans;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/rabbits-in-forest/
    */

    