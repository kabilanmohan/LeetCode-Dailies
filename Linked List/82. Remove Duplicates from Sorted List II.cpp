
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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode dummy(0);
        ListNode *curr = head , *temp = &dummy , *temphead = &dummy;

        int tempval = -101;
        while(curr)
        {
            
            if(!curr -> next || curr -> val != ((curr -> next) -> val)) 
            {
                temp -> next = curr;
                temp = temp -> next;
            }

            tempval = curr -> val;
            while(curr && curr -> val == tempval) 
            {
                tempval = curr -> val;
                curr = curr -> next;
            }
            
        }
        temp -> next = NULL;
        return temphead -> next;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
    */

    