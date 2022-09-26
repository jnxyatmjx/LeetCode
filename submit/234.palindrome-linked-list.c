/*
 * @lc app=leetcode id=234 lang=c
 *
 * [234] Palindrome Linked List
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
    struct ListNode *res= NULL, *cur;
    while(hd){
        cur = hd->next;
        hd->next = res;
        res = hd;
        hd = cur;
    }
    return res;
}

bool isPalindrome1(struct ListNode* head){
    //copy origin list
    struct ListNode *bd = head;
    struct ListNode nh, *cur = &nh;
    while(bd)
    {   cur->next = (struct ListNode*)calloc(1,sizeof(struct ListNode));
        cur = cur->next;
        cur->val = bd->val;
        bd = bd->next;
    }
    cur->next = NULL;

    //reverse new list
    cur = nh.next;
    nh.next = reverse(cur);

    //compare new and origin list
    bd = head;
    cur = nh.next;
    while(bd && cur){
        if(bd->val != cur->val)
            return false;
        bd = bd->next;
        cur = cur->next;
    }

    return true;
}

bool isPalindrome(struct ListNode* head){

    //find middle node in list
    struct ListNode *f=head, *s=head, *pre=s;
    while(f && f->next){
        pre = s;
        f = f->next->next;
        s = s->next;
    }
    if(f != NULL){//odd numbers lists
        s = s->next;
        if(pre->next) //split origin list write, tail next point to NULL
            pre->next->next = NULL;
    }else{
        pre->next = NULL;
    }
    
    
    struct ListNode *nh=s,*res=NULL, *cur;
    while(nh){
        cur = nh->next;
        nh->next = res;
        res = nh;
        nh = cur;
    }

    while(res){
        if(res->val != head->val) return false;
        res = res->next;
        head = head->next;
    }
    

    return true;
}
// @lc code=end

