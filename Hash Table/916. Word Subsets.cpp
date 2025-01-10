
    /*
    Time complexity : O(N+M)
    Space complexity : O(1)
    */


class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        // this was using a hashmap , use frequency array for a even better performance
        unordered_map <char,int> max_letter_count , curr_letter_count;
        vector<string> result;
        
        for(string i : words2)
        {
            for(char j : i)
            {
                if(!curr_letter_count.count(j)) curr_letter_count[j] = 1;
                else curr_letter_count[j]++;

                if(!max_letter_count.count(j)) max_letter_count[j] = 1;
                else
                {
                    if(curr_letter_count[j] > max_letter_count[j]) max_letter_count[j] = curr_letter_count[j];
                }
            }
            curr_letter_count.clear();
        }
        
        bool flag = true;
        for(string i : words1)
        {
            for(auto j : max_letter_count) if(count(i.begin() , i.end() , j.first) < j.second)
            {
                flag = false;
                break;
            } 
            if(flag) result.push_back(i);
            flag = true;
        }

        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/word-subsets/
    */

    