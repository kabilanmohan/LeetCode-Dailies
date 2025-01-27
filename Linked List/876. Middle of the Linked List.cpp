
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *slow = head , *fast = head;
        while(fast)
        {
            fast = fast -> next;

            if(fast) fast = fast -> next;
            else return slow;

            slow = slow -> next;
        }
        return slow;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/middle-of-the-linked-list/
    */

    