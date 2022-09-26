/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
      return true;
    }

    // find middle of the LinkedList
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *headSecondHalf = reverse(slow);  // reverse the second half
    ListNode *copyHeadSecondHalf =
        headSecondHalf;  // store the head of reversed part to revert back later
   
    // compare the first and the second half
    while (head != nullptr && headSecondHalf != nullptr) {
      if (head->val != headSecondHalf->val) {
        break;  // not a palindrome
      }
      head = head->next;
      headSecondHalf = headSecondHalf->next;
    }

    //this reverse operation can merge head and copyHeadSecondHalf into the origin list
    reverse(copyHeadSecondHalf);                         // revert the reverse of the second half
    if (head == nullptr || headSecondHalf == nullptr) {  // if both halves match
      return true;
    }
    return false;
  }

    ListNode *reverse(ListNode* hd){
        ListNode* res = NULL;
        while(hd){
            ListNode *cur = hd->next;
            hd->next = res;
            res = hd;
            hd = cur;
        }
        return res;
    } 
};
// @lc code=end

