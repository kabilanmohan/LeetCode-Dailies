class Solution {
public:
    // find all paths that lead to zero from bob
    bool bob_dfs(int curr , int time , vector<vector<int>> &graph , unordered_map<int,int> &path , vector<bool> &visited)
    {
        path[curr] = time;
        visited[curr] = true;
        if(curr == 0) return true;

        for(int i: graph[curr])
        {
            if(!visited[i])
            {
                if(bob_dfs(i , time+1 , graph , path , visited)) return true;
            }
        }

        path.erase(curr);
        return false;
    }

    bool alice_dfs(int curr , int time , unordered_map<int,int> &path , vector<vector<int>> &graph , vector<bool> &visited ,
     int sum , vector<int> &amount , int &result)
    {
        if(!path.count(curr)) sum += amount[curr];
        else
        {
            if(path[curr] == time) sum += amount[curr] / 2;
            else if(path[curr] > time) sum += amount[curr];
        }

        // leaf node condition
        if(curr != 0 && graph[curr].size() == 1) result = max(result , sum);

        visited[curr] = true;
        for(int i : graph[curr]) 
        {
            if(!visited[i])
            {
                if(alice_dfs(i , time+1 , path , graph , visited , sum , amount , result)) return true;
            }
        }
        return false;
    }


    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) 
    {
        int n = amount.size();
        vector<vector<int>> graph(n);
        
        for(auto &i: edges)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }

        unordered_map<int,int> path;
        vector<bool> visited(n+1 , false);

        bob_dfs(bob , 0 , graph , path , visited);

        for(auto i : visited) i = false;

        int sum = 0;
        int result = INT_MIN;
        alice_dfs(0 , 0 , path , graph , visited , sum , amount , result);

        return result;
        
    }
};
