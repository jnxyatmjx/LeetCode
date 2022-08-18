/*
 * @lc app=leetcode id=382 lang=c
 *
 * [382] Linked List Random Node
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



typedef struct {
    struct ListNode* hd;
} Solution;


Solution* solutionCreate(struct ListNode* head) {
    Solution * res = (Solution*)malloc(sizeof(Solution));
    res->hd = head;
    return res;
}

int solutionGetRandom(Solution* obj) {
    struct ListNode * hd = obj->hd;
    int res = 0,cnt = 1;
    struct ListNode *cur = hd;
    
    while(cur != NULL){
        if( rand()%cnt ==0 ){
            res = cur->val;
        }
        cnt++;
        cur = cur->next;
    }
    return res;
}

void solutionFree(Solution* obj) {
    struct ListNode* hd = obj->hd;
    while(hd !=NULL)
    {
        struct ListNode* cu = hd;
        hd = hd->next;
        free(cu);
    }

    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/
// @lc code=end

