/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
    struct ListNode hdump;hdump.next = head;//precursor of header
    
    struct ListNode* cur = head;
    int listLen = 0;
    while(cur)  //get length of this list
    {
        listLen++;
        cur = cur->next;
    }

    listLen -= n; //the precursor of Nth node ,precursor list length
    cur = &hdump; //!!!!! Caution CAUTION CAUTION !!!! Need ths precursor of header
     while(listLen > 0)
    {   
        cur = cur->next;
        listLen--;
    }
    cur->next = cur->next->next;

    return hdump.next;
}
// @lc code=end

