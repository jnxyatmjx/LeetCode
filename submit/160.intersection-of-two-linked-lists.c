/*
 * @lc app=leetcode id=160 lang=c
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    // p1 point to ListA header, p2 point to ListB header
    struct ListNode *p1 = headA, *p2 = headB;
    /*
            if listA and listB is intersect,
            nodes after intersection is exactly same (as a list subAB),
            so (listA + listB) and (listB + listA) all have list subAB
    */
    while (p1 != p2) {
        // p1 move one, if p1 reached tail of listA, p1 move to listB
        if (p1 == NULL) 
            p1 = headB;
        else            
            p1 = p1->next;

        // p2 move one, if p2 reached tail of listB, p2 move to listA
        if (p2 == NULL) 
            p2 = headA;
        else            
            p2 = p2->next;
    }
    return p2;//return p2;
}
// @lc code=end

