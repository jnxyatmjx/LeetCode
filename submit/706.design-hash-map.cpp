/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap {
public:
    MyHashMap() {
        data_.resize(1000001,-1);
    }
    
    void put(int key, int value) {
            data_[key] = value;
        
    }
    
    int get(int key) {
        if(data_[key] != -1)
            return data_[key];
        else
            return -1;
    }
    
    void remove(int key) {
         if(data_[key] != -1)
            data_[key] = -1;
    }

    std::vector<int> data_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

