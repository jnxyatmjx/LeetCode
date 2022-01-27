/*
 * @lc app=leetcode id=148 lang=c
 *
 * [148] Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
    Like Merge Sort
    1-> split orignal list into TWO (lft and rgt) lists. CAUTION {e.g. [1,9] need split into [1] and [9] }
    2-> recursive process list
    3-> merge the processed lists into ONE list

    Like Quick Sort
    1-> save list values into a Array
    2-> use quicksort on the Array
    3-> rebuild the result list from the Array
*/

//Merge two SORTED lists
struct ListNode* merg2Lists(struct ListNode* l1,struct ListNode* l2)
{
    struct ListNode dumph, *cur = &dumph;

    while(l1 && l2)
    {
        if(l1->val <= l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    cur->next = (l1!=NULL) ? l1 :l2;
    return dumph.next;
}

struct ListNode* sortList(struct ListNode* head){
    
    if(!head || !head->next/*for recursive return base case*/) 
        return head;
    
    //find middle node, split into two lists 
    //{e.g. [1,9] need split into [1] and [9] }
    struct ListNode *fast=head, *slow=head, *pre=head;
    while(fast && fast->next)
    {
        pre=slow;
        fast=fast->next->next;
        slow=slow->next;
    }
    pre->next=NULL;

    return merg2Lists(sortList(head), sortList(slow));
}

// @lc code=end

