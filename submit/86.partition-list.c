/*
 * @lc app=leetcode id=86 lang=c
 *
 * [86] Partition List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode dump1, *l1 = &dump1; dump1.next=NULL;
    struct ListNode dump2, *l2 = &dump2; dump2.next=NULL;

    while(head != NULL)
    {
        if(head->val < x)
        {
            l1->next = head;
            l1 = l1->next;
        }else{
            l2->next = head;
            l2 = l2->next;
        }
        head = head->next;
    }
    l1->next=NULL; l2->next=NULL;//split origin list

    if (dump1.next != NULL)
        l1->next = dump2.next;
    
    return dump1.next != NULL ? dump1.next : dump2.next;

}
// @lc code=end

