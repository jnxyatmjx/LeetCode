/*
 * @lc app=leetcode id=92 lang=c
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    /*
        this function will separate the original list into three partition
        first is original list AA
        second is reversed partition BB
        last is after reverse list CC
    */
    
    //add precursor node for the original list's head
    struct ListNode pre_newhead;
    pre_newhead.next = head;
    
    //find the precursor node of the left position node
    struct ListNode* pre_left = &pre_newhead;
    for(int i = 1; i < left && pre_left; i++ ){
        pre_left = pre_left->next;
    }
    
    //reverse operation will separate the original list into tow sublists 
    //CAUTION this two sublists all have tail NULL
    //cur and head_new will point the second sublist,and res will point the first sublist
    struct ListNode* head_new = pre_left->next;
    struct ListNode* res = NULL;
    struct ListNode* cur;
    for(int i = left; i <=right && head_new; i++)
    {
        cur = head_new->next;
        head_new->next = res;
        res = head_new;
        head_new = cur;
    }
    pre_left->next = res;//list AA link the BB list
    
    
    //find the second BB list's last node
    struct ListNode* cur_3 = res;
    while(cur_3->next)
    {   
        cur_3 = cur_3->next;
    }
    cur_3->next = cur;//list BB likn the CC list
        

    return pre_newhead.next;
}
// @lc code=end

