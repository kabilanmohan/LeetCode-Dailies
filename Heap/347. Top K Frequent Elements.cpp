
    /*
    Time complexity : O(nlogk)
    Space complexity : O(n)
    */


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> freq;
        for(auto i:nums)
        {
            if(!freq.count(i)) freq[i] = 1;
            else freq[i]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> topk;

        for(auto iter: freq)
        {   
            topk.push(make_pair(iter.first,iter.second));
            if(topk.size() > k) topk.pop();
        }

        vector<int> result;
        while(!topk.empty())
        {
            result.push_back(topk.top().second);
            topk.pop();
        }
        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/top-k-frequent-elements/
    */

    