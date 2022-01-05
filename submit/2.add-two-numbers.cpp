/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dumph ,*cur = &dumph;
    
        int cary=0;
        while(cary!=0 || l1!=NULL || l2!=NULL)
        {
            cary += (l1 != NULL) ? l1->val : 0;
            cary += (l2 != NULL) ? l2->val : 0;

            cur->next = new ListNode(cary%10);
            
            cur = cur->next;
            cary /= 10;

            if(l1) l1=l1->next;
            if(l2) l2=l2->next;

        }

        return dumph.next;
    }
};
// @lc code=end

