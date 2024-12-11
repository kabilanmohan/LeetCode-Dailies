
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
    ListNode* swapPairs(ListNode* head) 
    {
        if(!head) return head;
        if(!head -> next) return head;

        ListNode dummy(0);
        ListNode *curr1 = head , *curr2 = head -> next , *temp = head , *prev = &dummy;
        head = curr2;

        while(curr2)
        {
            temp = curr2 -> next;

            curr1 -> next = curr2 -> next;
            curr2 -> next = curr1;

            // dont forget to maintain a prev node to the current curr1 & curr2 and then assigning that node's next to current curr2;
            prev -> next = curr2;
            prev = curr1;
            
            curr1 = temp;
            if(temp) curr2 = temp -> next;
            else curr2 = NULL;
        }
        return head;
        
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/swap-nodes-in-pairs/
    */

    