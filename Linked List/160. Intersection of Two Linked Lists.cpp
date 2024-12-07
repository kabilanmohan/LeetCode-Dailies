
    /*
    Time complexity : O(m+n)
    Space complexity : O(1)
    */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        // storing heads in a temp pointer
        ListNode *tempheadA = headA , *tempheadB = headB;

        //finding lengths of both lists
        int len1 = 1, len2 = 1;
        while(headA -> next || headB -> next)
        {
            if(headA -> next)
            {
                headA = headA -> next;
                len1 ++;
            }
            if(headB -> next)
            {
                headB = headB -> next;
                len2 ++;
            }
        }
        if(headA != headB) return NULL; // if tails of both lists doesnt match , means no intersection
    
        /* if len of list1 is larger , we move temphead pointer of list A by diff in length of both lists to 
        match the length of both lists hence after we can move both pointers by one step each and find common 
        node
        */
        if(len1 > len2)
        {
            len1 = len1 - len2;
            for(int i = 1 ; i <= len1 ; i++) tempheadA = tempheadA -> next;
        }
        else
        {
            len2 = len2 - len1;
            for(int i = 1 ; i <= len2 ; i++) tempheadB = tempheadB -> next;
        }

        // move both pointers by one step each till reaching the same node
        while(tempheadA && tempheadB)
        {
            if(tempheadA == tempheadB) return tempheadA;
            tempheadA = tempheadA -> next;
            tempheadB = tempheadB -> next;
        }
        return NULL;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/intersection-of-two-linked-lists/
    */

    