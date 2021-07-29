/*
 * @lc app=leetcode id=109 lang=c
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#if 0
struct TreeNode* createNode(int val)
{
    struct TreeNode* node = (struct TreeNode*)calloc(1,sizeof(struct TreeNode));
    node->val = val;
    return node;
}

// this algorithm has Time Complexity O(NlogN) ,Space Complexity O(logN)
//[head,tail)
struct TreeNode* bltTree(struct ListNode* head,struct ListNode* tail)
{
    if(head == tail) return NULL;
    
    // fast and slow pointer can find middle node of this list
    struct ListNode* fast = head,*slow = head;
    while(fast != tail && fast->next != tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    //find the middle node of this list ,slow IS

    struct TreeNode* node = createNode(slow->val);

    //process left subtree with subleft list 
    node->left = bltTree(head,slow);

    //process right subtree with subright list
    node->right = bltTree(slow->next,tail);

    return node;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head == NULL) return NULL;
    return bltTree(head,NULL);
}
#endif

//this algorithm has Time Complexity O(N) and Space Complexity O(logN)
int getLength(struct ListNode* head) {
    int ret = 0;
    while (head != NULL) {
        ++ret, head = head->next;
    }
    return ret;
}

//[left ,right]
struct TreeNode* buildTree(struct ListNode** head, int left, int right) {
    if (left > right) {
        return NULL;
    }
    //int mid = (left + right + 1) / 2;
    int mid = left + (right - left)/2; //different from above mid position
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left = buildTree(head, left, mid - 1);
    root->val = (*head)->val;
    (*head) = (*head)->next;
    root->right = buildTree(head, mid + 1, right);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int length = getLength(head);
    return buildTree(&head, 0, length - 1);
}
// @lc code=end

