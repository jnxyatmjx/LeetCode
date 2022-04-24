/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet {
public:
/** Initialize your data structure here. */
MyHashSet() {
    data.resize(1000001, false);
}

void add(int key) {
    data[key] = true;
}

    void remove(int key) {
        data[key] = false;
    }

/** Returns true if this set contains the specified element */
    bool contains(int key) {
        return data[key] == true;
    }

private:
    vector<bool> data;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

