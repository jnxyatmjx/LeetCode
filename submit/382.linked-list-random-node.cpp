/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    Solution(ListNode* head) {
        hd = head;
    }
    
    int getRandom() {
        
        ListNode* cur = hd;
        int cnt = 1;
        int res = cur->val;
        while (cur != NULL)
        {
            if(rand() % cnt == 0) res = cur->val;

            cnt++;
            cur = cur->next;
        }
        return res;
    }
private:
    ListNode* hd;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

