
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class MinStack {
public:
    stack <pair<int,int>> min_s;
    int curr_min = INT_MAX;

    MinStack() {
        curr_min = INT_MAX;
    }
    
    void push(int val) {
        if(min_s.empty()) 
        {
            min_s.push({val,val});
            curr_min = val;
        }
        else
        {
            if(val < min_s.top().second) 
            {
                min_s.push({val,val});
                curr_min = val;
            }
            else min_s.push({val,curr_min});
        }
    }
    
    void pop() {
        if(min_s.top().first == curr_min)
        {
            min_s.pop();
            if(!min_s.empty()) curr_min = min_s.top().second;
        }
        else min_s.pop();
    }
    
    int top() {
        return min_s.top().first;
    }
    
    int getMin() {
        return min_s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/min-stack/
    */

    