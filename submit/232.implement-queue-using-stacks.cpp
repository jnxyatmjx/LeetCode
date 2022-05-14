/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
private:
    /*
            Sh                   St
        queue header <---> queue tailer

        1:Push data to St
        2: if Sh is empty, move all St's data to Sh
           is Sh not empty, Pop Sh.       
    */
    std::deque<int> Sh, St;

public:
    MyQueue() {
        Sh.clear();
        St.clear();
    }
    
    void push(int x) {
        St.push_back(x); //just push to queue tailer
    }
    
    int pop() {
        int v = peek();
        Sh.pop_back();
        return v;
    }
    
    int peek() {
        if(Sh.empty())
            while(!St.empty())
            {
                Sh.push_back(St.back());
                St.pop_back();
            }
        return Sh.back();
    }
    
    bool empty() {
        return Sh.empty() && St.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

