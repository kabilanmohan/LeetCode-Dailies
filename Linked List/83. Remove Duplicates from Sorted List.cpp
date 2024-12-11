
    /*
    Time complexity : O(N)
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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *curr = head , *temp = head;

        int tempval = 0;
        while(curr)
        {
            tempval = curr -> val;
            temp = curr;
            while(curr && curr -> val == tempval)
            {
                curr = curr -> next;
            }
            temp -> next = curr;
            temp = temp -> next;
        }
        return head;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
    */

    