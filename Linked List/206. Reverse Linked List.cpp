
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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *curr = head , *prev = NULL , *after = head;
        if(head == NULL) return head;

        after = after -> next;
        while(curr != NULL)
        {
            curr -> next = prev;
            prev = curr;
            curr = after;
            if(after)after = after -> next;
        }
        return prev;

    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/reverse-linked-list/
    */

    