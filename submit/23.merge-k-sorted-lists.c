/*
 * @lc app=leetcode id=23 lang=c
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode head,*curr = &head;
    head.next = NULL;

    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }

        curr = curr->next;
    }

    curr->next = l1 ? l1 : l2;

    return head.next;
}

struct ListNode* mergeList(struct ListNode** lists,int l,int r)
{
    if(l == r) return lists[l];
    
    if(l > r) return NULL;

    int mid = l + (r - l)/2;
    return mergeTwoLists( mergeList(lists,l,mid), mergeList(lists,mid+1,r) );

    /*
        What is it
        amount = len(lists)
        interval = 1
        while interval < amount:
            for i in range(0, amount - interval, interval * 2):
                lists[i] = self.merge2Lists(lists[i], lists[i + interval])
            interval *= 2
        return lists[0] if amount > 0 else None
    
    */
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    return mergeList(lists,0,listsSize -1);
}
// @lc code=end

