/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
//[1,2,3,4,5,6,7,8,9,10,123,2345,123123,123123,123,11]\n
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode  hodd, heven;
        ListNode *codd=&hodd, *ceven=&heven;
        
        //first -> separe origin list into odd and even list
        //second-> merge them

        for(int i=1; head != NULL; i++)
        {   
            if((i&1) == 1) //need(),because priority of == is higher than &
            {
                codd->next = head;
                codd = codd->next;
            }
            else{ //even list
                ceven->next = head;
                ceven = ceven->next;
            }
            head = head->next;
        }
        codd->next = heven.next;
        ceven->next = NULL;

        return hodd.next;
    }
};
// @lc code=end

