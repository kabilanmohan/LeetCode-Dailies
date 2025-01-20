
    /*
    Time complexity : O(m*n)
    Space complexity : O(m*n)
    */


class Solution {
public:
    // O(m*n) unordered map slower
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        unordered_map<int,pair<int,int>> location;
        int row_size = mat.size() , col_size = mat[0].size();

        for(int i = 0 ; i < row_size ; i++)
        {
            for(int j = 0 ; j < col_size ; j++) location[mat[i][j]] = {i,j};
        }
        vector<int> rows (row_size,0) , cols(col_size,0);

        for(int i = 0 ; i < arr.size() ; i++)
        {
            auto curr = location[arr[i]];
            rows[curr.first]++;
            cols[curr.second]++;

            if(rows[curr.first] == col_size || cols[curr.second] == row_size) return i;
        }
        return -1;
    }
    // O(m*n) array to store (faster)
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        vector<pair<int,int>> location(arr.size()+1);
        int row_size = mat.size() , col_size = mat[0].size();

        for(int i = 0 ; i < row_size ; i++)
        {
            for(int j = 0 ; j < col_size ; j++) location[mat[i][j]] = {i,j};
        }
        vector<int> rows (row_size,0) , cols(col_size,0);

        for(int i = 0 ; i < arr.size() ; i++)
        {
            auto curr = location[arr[i]];
            rows[curr.first]++;
            cols[curr.second]++;

            if(rows[curr.first] == col_size || cols[curr.second] == row_size) return i;
        }
        return -1;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/first-completely-painted-row-or-column/
    */

    