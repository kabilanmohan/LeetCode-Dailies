
    /*
    Time complexity : O(M+N)
    Space complexity : O(max(m,n))
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        // dummy node to store result
        ListNode dummy(0);
        ListNode *result = &dummy , *curr = &dummy;

        int carry = 0 , sum = 0;
        
        // loop until there is l1 or l2 or carry
        while(l1 || l2 || carry)
        {
            if(l1) 
            {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            
            if(l2)
            {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            sum += carry;

            if(sum > 9) 
            {
                carry = 1;
                sum = sum % 10;
            } 
            else carry = 0;

            /*
            I tried first by 
                ListNode temp(sum);
                curr -> next = &temp;

            but that lead to a memory error because the memory of temp is released once after the iteration 
            is completed as it was declared inside the loop.

            so do by the way given in the below line

            */
            curr -> next = new ListNode(sum);
            curr = curr -> next;

            sum = 0;
        }
        return result -> next;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/add-two-numbers/
    */

    