
    /*
    Time complexity : O(N)
    Space complexity : O(N)
    */


class Solution {
public:
    // using a pair of integers to store the temperature along with the index
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        stack <pair<int,int>> numindex_stack;
        int n = temperatures.size();
        vector<int> result(n , 0);

        for(int i = 0 ; i < n ; i++)
        {    
            while(!numindex_stack.empty() && temperatures[i] > numindex_stack.top().first)
            {
                pair<int,int> temp = numindex_stack.top();
                numindex_stack.pop();
                result[temp.second] = abs(i - temp.second);
            }

            numindex_stack.push({temperatures[i] , i});
        }    
        return result;
    }

    // 26ms faster than previous approach cuz of using int to store just the index and not a pair of int
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        stack <int> index_stack;
        int n = temperatures.size();
        vector<int> result(n , 0);

        for(int i = 0 ; i < n ; i++)
        {    
            while(!index_stack.empty() && temperatures[i] > temperatures[index_stack.top()])
            {
                result[index_stack.top()] = abs(i - index_stack.top());
                index_stack.pop();
            }

            index_stack.push(i);
        }    
        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/daily-temperatures/
    */

    