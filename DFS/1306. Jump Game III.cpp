
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(),false);
        return func_reach(arr,start,visited);
    }

    bool func_reach(vector<int>& arr, int start,vector<bool> &visited)
    {
        if(start<0 || start > arr.size()-1) return false;
        if(arr[start] == 0) return true;
        if(visited[start] == true) return false;
        visited[start] = true;
        return func_reach(arr, start - arr[start],visited) || 
        func_reach(arr, start + arr[start],visited);
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/jump-game-iii/description/
    */

    