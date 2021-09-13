/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA, *p2 = headB;
        /*
            if listA and listB is intersect,
            nodes after intersection is exactly same (as a list subAB),
            so (listA + listB) and (listB + listA) all have list subAB
        */
        while(p1 != p2)
        {
            if(p1 == NULL) p1 = headB;
            else p1 = p1->next;

            if(p2 == NULL) p2 = headA;
            else p2 = p2->next;
        }
        return p1;
    }
};
// @lc code=end

