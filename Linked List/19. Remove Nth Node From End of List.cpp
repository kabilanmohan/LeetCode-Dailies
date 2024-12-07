
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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        // initialize a dummy node
        ListNode dummy(0);
        ListNode *curr = &dummy;
        curr = head;
        
        // fast slow pointers , move fast pointer n times
        ListNode *fast = head , *slow = head;
        for(int i = 1 ; i <= n ; i++) fast = fast -> next;

        // if fast points to null, it means we have to delete the head of list
        if(!fast) return head -> next;

        // move slow and fast one step till fast reaches the last node
        while(fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next;
        }

        // delete the slow's next node by assigning slow's next as next's next
        if(slow -> next) slow -> next = (slow -> next) -> next;
        else slow = slow -> next;

        // return head
        return head;

    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
    */

    