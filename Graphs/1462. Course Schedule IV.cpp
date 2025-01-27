
    /*
    Time complexity : O(V+E+P)
    Space complexity : O(V^2)
    */


class Solution {
public:
    // need to be made better
    unordered_set<int> dfs(int node , vector<vector<int>> &graph , vector<unordered_set<int>> &node_to_prereq)
    {
        if(node_to_prereq[node].empty())
        {
            unordered_set<int> result;
            for(auto neighbor : graph[node])
            {
                unordered_set<int> temp = dfs(neighbor , graph, node_to_prereq);
                result.insert(temp.begin(), temp.end()); // union 2 sets
            }
            result.insert(node);
            node_to_prereq[node] = result;
        }
        return node_to_prereq[node];
    }

    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        vector<vector<int>> graph(numCourses);

        for(auto i : prerequisites)
        {
            graph[i[1]].push_back(i[0]);
        }
        
        vector<unordered_set<int>> node_to_prereq (numCourses);
        
        for(int i = 0 ; i < numCourses ; i++)
        {
            node_to_prereq[i] = dfs(i , graph, node_to_prereq);
        }

        vector<bool> result;

        for(auto i : queries)
        {
            if(node_to_prereq[i[1]].count(i[0])) result.push_back(true);
            else result.push_back(false);
        }
        return result;

    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/course-schedule-iv/
    */

    