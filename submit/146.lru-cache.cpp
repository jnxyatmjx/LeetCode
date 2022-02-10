/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
private:
    class LinkedListNode {
    public:
        int key;
        int data;
        LinkedListNode* next;
        LinkedListNode* prev;

        LinkedListNode(int data) {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }

        LinkedListNode(int key, int data) {
            this->key = key;
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }

        LinkedListNode(int data, LinkedListNode* next) {
            this->data = data;
            this->next = next;
            this->prev = NULL;
        }

        LinkedListNode(int data, LinkedListNode* next, LinkedListNode* prev) {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }

        ~LinkedListNode(){
            delete this->next;
            delete this->prev;
        }
};


class LinkedList { 

    public:
        LinkedListNode* head;
        LinkedListNode* tail;
        int size;
        
        LinkedList(){
            this->head = NULL;
            this->tail = NULL;
            this->size = 0;
        }
        
        void insertAtHead(int key, int data) {

            LinkedListNode* newNode = new LinkedListNode(key, data);
            if(this->head == NULL){
                this->head = newNode;
                this->tail = newNode;
            }
            else{
                newNode->next = this->head;
                this->head->prev = newNode;
                this->head = newNode;
            }
            this->size++;
        }

        void insertAtTail(int key, int data) {
            LinkedListNode* newNode = new LinkedListNode(key, data);
            if (this->tail == NULL){
                this->tail = newNode;
                this->head = newNode;
                newNode->next = NULL;
                newNode->prev = NULL;
            }
            else{
                this->tail->next = newNode;
                newNode->prev = this->tail;
                this->tail = newNode;
                newNode->next = NULL;
            }
            this->size++;
        }

        LinkedListNode* getHead(){
            return this->head;
        }
        
        LinkedListNode* getTail(){
            return this->tail;
        }

        LinkedListNode* removeNode(LinkedListNode* node){
            if(node == NULL){
                return NULL;
            }

            if(node->prev != NULL){
                node->prev->next = node->next;
            }

            if(node->next != NULL){
                node->next->prev = node->prev;
            }

            if(node == this->head){
                this->head = this->head->next;
            }
            if(node == this->tail){
                this->tail = this->tail->prev;
            }
            this->size--;
            return node;
        }
    //Time O(N)
        void remove(int data){
            auto i = this->getHead();
            while(i != NULL){
                if(i->data == data){
                    this->removeNode(i);
                }
                i = i->next;
            }     
        }

        LinkedListNode* removeHead(){
            return this->removeNode(this->head);
        }

        LinkedListNode* removeTail(){
            return this->removeNode(this->tail);
        }

        int listSize(){
            return size;
        }
};

    LinkedList cache; //Header is the recently used cache node
    int cap;
    unordered_map<int/*cache's key*/,LinkedListNode*> idx;
public:
    LRUCache(int capacity) {
        cap = capacity;
        idx.clear();
    }
    
    int get(int key) {
        if(idx.count(key) > 0 )
        {
            //Get the Key
            LinkedListNode* tepv = idx[key];

            //Remove origin value and Set this key to Header
            cache.removeNode(tepv);
            cache.insertAtHead(tepv->key,tepv->data); 
            idx.erase(key);//erase will automatic destruct the node
            idx[key] = cache.getHead();
            return cache.getHead()->data;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(idx.count(key) > 0)
        {
            //get the Key
            LinkedListNode* tepv = idx[key];

            //Set this key to Header
            cache.removeNode(tepv);
            cache.insertAtHead(key,value); 
            idx.erase(key);//erase will automaticly destruct the value
            idx[key] = cache.getHead();
        }
        else{ //need insert 
                if(cache.listSize() >= cap)
                {
                    LinkedListNode *rev = cache.removeTail();//Remove the Tailer
                    idx.erase(rev->key);//delete rev, is Error.unordered_map erase will destruct the node pointer
                }
                    
                //Just insert into Header
                cache.insertAtHead(key,value);
                idx[key] = cache.getHead();
            }
    }//end function
};

/**
 * ["LRUCache","put","put","put","put"]\n[[2],[1,1],[2,2],[3,3],[3,9]]\n
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

