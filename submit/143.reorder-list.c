/*
 * @lc app=leetcode id=143 lang=c
 *
 * [143] Reorder List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* hd){
    if (hd==NULL) return NULL;
    struct ListNode* res = NULL;
    while(hd){
        struct ListNode* cur = hd->next;
        hd->next = res;
        res = hd;
        hd = cur;
    }
    return res;
}

void reorderList(struct ListNode* head){

    //spilite list
    /*if 1,2,3   split into 1,2 and 3
      if 1,2,3,4 split into 1,2,3 and 4*/
    struct ListNode *s=head,*f=head;
    while (f && f->next)
    {   
        f = f->next->next;
        s = s->next;
    }
    struct ListNode *newhd = reverse(s->next/*not normal split*/);s->next = NULL;
    

    struct ListNode *orihd = head; 
    while(newhd && orihd){
        struct ListNode* cur = orihd->next;
        orihd->next = newhd;
        orihd = cur;

        cur = newhd->next;
        newhd->next = orihd;
        newhd = cur;
    }
    //if(newhd != NULL)
    //    orihd->next = newhd;

}
// @lc code=end

