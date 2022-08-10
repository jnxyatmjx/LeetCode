/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* t = head;
        Node dump(-10001),*cur = &dump;
        map<Node*,Node*> indx; // origin node as key, and new node as value
        while (head!=NULL)
        {
            Node *node = new Node(head->val);
            indx[head] = node;
            
            cur->next = node;
            cur = cur->next;

            head = head->next;
        }
        cur = dump.next; head = t;
        while(head != NULL){
            cur->random = indx[head->random];
            head = head->next;
            cur = cur->next;
        }
        
        return dump.next;
    }
};
// @lc code=end

