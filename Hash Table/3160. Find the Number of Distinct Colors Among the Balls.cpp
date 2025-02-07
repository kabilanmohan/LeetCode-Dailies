
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) 
    {
        unordered_map<int, int> index_to_color;
        unordered_map<int, int> color_count;
        vector<int> result;

        for(auto& q : queries)
        {
            int index = q[0], color = q[1];
            if(index_to_color.count(index)) 
            {
                int old_color = index_to_color[index];
                if(--color_count[old_color] == 0) color_count.erase(old_color);  
            }
            index_to_color[index] = color;
            color_count[color]++;

            result.push_back(color_count.size());
        }

        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls
    */

    