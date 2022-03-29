/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        return mergeK(lists,0,lists.size()-1);
    }

    //std::size_t is overflow when lists is empty()!!!!
    //lft rgt may be negative 
    ListNode* mergeK(vector<ListNode*>& lists, int lft, int rgt)
    {
        //printf("lft:%d rgt:%d\n",lft,rgt);
        //if( lft >= rgt) // this condition is error and why
        //    return lists[lft]; // lists[rgt] is error when lists is empty

        if(lft == rgt) return lists[lft];
        if(lft > rgt) return NULL;
        
        int mid = lft + (rgt-lft)/2;

        return merge2( mergeK(lists,lft,mid) , mergeK(lists,mid+1,rgt) );
    }

    ListNode* merge2(ListNode* l1, ListNode* l2)
    {
        ListNode hdump, *cur = &hdump;
        hdump.next = NULL;

        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        cur->next = (l1!=NULL) ? l1 : l2;
        return hdump.next;
    }
};
// @lc code=end

