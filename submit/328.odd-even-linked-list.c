/*
 * @lc app=leetcode id=328 lang=c
 *
 * [328] Odd Even Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){

    //separe origin list into oddlist and evenlist
    struct ListNode hodd,*codd = &hodd;
    struct ListNode heven,*ceven = &heven;

    for(int i=1; head!=NULL; i++)
    {
        if((i&1)==1)//odd
        {
            codd->next = head;
            codd = codd->next;
        }
        else //even
        {
            ceven->next = head;
            ceven = ceven->next;
        }
        head = head->next;
    }

    //merge oddlist and evenlist
    codd->next = heven.next;
    ceven->next = NULL;

    heven.next = NULL; //just for leetcode cases passed!!
    
    return hodd.next;
}
// @lc code=end

