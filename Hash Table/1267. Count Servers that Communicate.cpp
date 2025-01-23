
    /*
    Time complexity : O(m*n)
    Space complexity : O(m+n)
    */


class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {
        int rows = grid.size() , cols = grid[0].size();
        vector<int> row_count (rows , 0) , col_count (cols , 0);

        int nodes = 0;

        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < cols ; j++)
            {
                if(grid[i][j] == 1)
                {
                    row_count[i]++;
                    col_count[j]++;
                    nodes++;
                }
            }
        }

        int single_node_count = 0;

        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < cols ; j++)
            {
                if(grid[i][j] == 1 && row_count[i] <= 1 && col_count[j] <= 1) single_node_count++;
            }
        }
        return nodes - single_node_count;


    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/count-servers-that-communicate/
    */

    