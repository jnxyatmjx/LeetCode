/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
#include <cstddef>
class MyLinkedList
{
private:
    typedef struct LinkNode
    {
        int val;
        LinkNode *next;
        LinkNode(int v)
        {
            val = v;
            next = NULL; // next MUST BE NULL
        }
    } LinkNode;
    LinkNode *head;
    LinkNode *tail;

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head = NULL;
        tail = head;
    }

    /*return pointer of a Node's previous*/
    LinkNode *PreofNode(LinkNode *val)
    {
        if (!head)
            return NULL;
        LinkNode *res = head;
        while (res->next != NULL && res->next != val)
        {
            res = res->next;
        }
        if (res->next == val)
            return res;
        else
            return NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is
     * invalid, return -1. */
    int get(int index)
    {
        if (head == NULL)
            return -1;
        LinkNode *cur = head;

        // find the Current Node in the List
        int i = 0;
        for (; cur && i < index; i++)
        {
            cur = cur->next;
        }

        if (i == index && cur)
            return cur->val;
        else
            return -1;
    }

    /** Add a node of value val before the first element of the linked list.
     * After the insertion, the new node will be the first node of the linked
     * list. */
    void addAtHead(int val)
    {
        LinkNode *temp = new LinkNode(val);

        temp->next = head;
        head = temp;

        // Update the tail pointer
        if (head->next == NULL)
            tail = head;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        LinkNode *temp = new LinkNode(val);

        if (tail == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->next = NULL;
        }

        // Update tail pointer
        tail = temp;
    }

    /** Add a node of value val before the index-th node in the linked list. If
     * index equals to the length of linked list, the node will be appended to
     * the end of linked list. If index is greater than the length, the node
     * will not be inserted. */
    void addAtIndex(int index, int val)
    {
        /* //if(head == NULL) return; //绝对不能直接返回 巨坑//    */
        LinkNode *cur = head;
        int i = 0;
        for (; cur && i < index; i++)
        { // find the Current Node
            cur = cur->next;
        }
        if (i == index && cur)
        { // index is always valid and list NOT NULL

            LinkNode *pre = PreofNode(cur);
            if (pre == NULL)
            {
                // 非空链表 首节点
                LinkNode *temp = new LinkNode(val);
                temp->next = head;
                head = temp;
            } // pre == NULL
            else
            { // pre != NULL
                LinkNode *temp = new LinkNode(val);
                temp->next = cur;
                pre->next = temp;
            }

        } // END ALL if

        // 正好为链表长度
        if (index == i && cur == NULL)
        {
            if (head == NULL)
            {
                head = new LinkNode(val);
                tail = head;
            }
            else
            {
                LinkNode *temp = new LinkNode(val);
                tail->next = temp;
                temp->next = NULL;
                tail = temp;
            }
        } // 正好为链表长度
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (head == NULL)
            return;
        LinkNode *cur = head;
        int i = 0;
        for (; cur && i < index; i++)
        { // find the Current Node
            cur = cur->next;
        }

        if (i == index && cur)
        { // index is always valid and list NOT NULL

            if (cur == head)
            { // header node
                LinkNode *temp = cur;
                if (head == tail) // origin list have only one node
                    tail = NULL;
                head = head->next;
                delete (temp);
                return;
            } // END

            if (cur == tail)
            { // tail node
                LinkNode *pre = PreofNode(cur);
                LinkNode *temp = cur;
                pre->next = cur->next;
                delete (temp);
                if (pre == head)
                {
                    tail == head;
                }
                if (pre->next == NULL)
                {
                    tail = pre;
                }
                return;
            }

            // normal station
            LinkNode *pre = PreofNode(cur);
            LinkNode *temp = cur;
            pre->next = cur->next;
            delete (temp);

        } // end index right IF
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

