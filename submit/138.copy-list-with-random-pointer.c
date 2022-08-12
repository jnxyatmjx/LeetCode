/*
 * @lc app=leetcode id=138 lang=c
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
//https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247492747&idx=1&sn=1c30855f75abbe6507d6fe23698c3f58&chksm=fd9f4f94cae8c6822a15742063d9368f4500f23315c510fddab1f3090a4ce8d7ffd61a249593&scene=178&cur_album_id=1936977672195096585#rd
void printfl(struct Node* head)
{
    while(head!=NULL){
        printf("val:%d random:%d ",head->val,(head->random != NULL ? head->random->val:-1));
        head = head->next;
    }
    printf("\n");
}

struct Node* copyRandomList(struct Node* head) {
	struct Node* t = head;
    
    // add new nodes behind origin node
    while(head!=NULL)
    {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
        node->val = head->val;node->random=NULL;

        node->next = head->next;
        head->next = node;
        head = node->next;
    }
    
    // exchange random node 
    head = t;
    while(head !=NULL)
    {
        if(head->random!=NULL) 
            head->next->random = head->random->next;
        head = head->next->next;
    }

    head = t;
    struct Node dumporigin, *co = &dumporigin; //origin list of origin
    struct Node dumpnew, *cn = &dumpnew;        // new list of result
    while(head !=NULL)
    {
        // origin list node 
        co->next = head; co=co->next; head = head->next;

        // new list node
        if(head != NULL){
            cn->next = head;
            cn = cn->next;
            head = head->next;
        }
    }
    cn->next=NULL; co->next=NULL;
    
    return dumpnew.next;
}
// @lc code=end

