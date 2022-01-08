/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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

/*
    1.Reverse lists and similar to 2.add-two-numbers
    2.Stack to simulate the Reverse List
*/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        //use stack to simulate the reverse list
       deque<int> s1,s2;

       while(l1)
       {
           s1.push_front(l1->val);
           l1=l1->next;
       } 

       while(l2)
       {
           s2.push_front(l2->val);
           l2=l2->next;
       }

        ListNode dumpd,*cur = &dumpd;
       int cary=0;
       while(cary>0 || s1.size()>0 || s2.size()>0 )
       {
           cary += (s1.size()>0) ? s1.front() : 0;
           cary += (s2.size()>0) ? s2.front() : 0;

           cur->next = new ListNode(cary % 10);
           cur=cur->next;
           cary /= 10;
           
           if(!s1.empty()) s1.pop_front();
           if(!s2.empty()) s2.pop_front();
       }
       
       return reverse(dumpd.next);
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* res=NULL,*cur;
        while(head)
        {
            cur = head->next;
            head->next = res;
            res = head;
            head = cur;
        }
        return res;
    }
};
// @lc code=end

