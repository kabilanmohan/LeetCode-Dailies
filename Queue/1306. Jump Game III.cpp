
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;       // initialize queue
        vector<bool> visited(arr.size(),false);

        q.push(start);              //pushing in queue
        visited[start] = true;

        while(!q.empty())           // checking queue empty or not
        {
            int idx = q.front();    // only .front() return values
            q.pop();                // pop doesnt return a value

            if(arr[idx] == 0) return true;

            if((idx+arr[idx] <= arr.size()-1) && 
            (visited[idx+arr[idx]] ==  false)) 
            {
                visited[idx+arr[idx]] = true;
                q.push(idx+arr[idx]);
            }
            if((idx-arr[idx] >= 0) && 
            (visited[idx-arr[idx]] ==  false)) 
            {
                visited[idx-arr[idx]] = true;
                q.push(idx-arr[idx]);
            }
        }
        return false;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/jump-game-iii/
    */

    