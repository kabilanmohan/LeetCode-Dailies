
    /*
    Time complexity : O(V+E)
    Space complexity : O(V+E)
    */


class Solution {
public:

    // use union find for a better implementation later
    bool dfs(int node , int parent , int &cycle_start , vector<vector<int>> &adj , vector<bool> &visited ,unordered_set<int>& in_cycle)
    {
        if(visited[node])
        {
            cycle_start = node;
            return true;
        }
        visited[node] = true;
        for(int i : adj[node])
        {
            if(i == parent) continue;
            if(dfs(i , node , cycle_start , adj , visited , in_cycle))
            {
                if(cycle_start != -1) in_cycle.insert(node);
                if(node == cycle_start) cycle_start = -1;
                return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        vector<vector<int>> adj(n+1);

        for(auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);

        }
        
        vector<bool> visited(n+1 , false);
        unordered_set<int> in_cycle;
        int cycle_start = -1;

        dfs(1 , -1 , cycle_start , adj , visited , in_cycle);

        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(in_cycle.count(edges[i][0]) && in_cycle.count(edges[i][1])) return edges[i];
        }

        return {};
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/redundant-connection/
    */

    