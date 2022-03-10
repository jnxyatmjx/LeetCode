/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
private:
    priority_queue<int> maxHeap;                             // containing first half of numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;  // containing second half of numbers
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //We decide to minHeap have more element than maxheap
        
        // num greater or equal to top minHeap, insert it into minHeap
        if(minHeap.empty() || minHeap.top() <= num)
        {
            minHeap.push(num);
        }else// num smaller than top minHeap, insert int into maxHeap
        {
            maxHeap.push(num);
        }
        
        /*
            Means the the initial state is minHeap==maxHeap+1
            and num INSERT into minHeap, Balance minHeap
        */
        if(minHeap.size() > maxHeap.size()+1)
        {
            maxHeap.push(minHeap.top()); minHeap.pop();
        }
        /*
            Mean the initial state is minHeap == maxHeap
            and number INSERT INTO maxHeap, Balance maxHeap
        */
        else if(minHeap.size() < maxHeap.size())
        {
            minHeap.push(maxHeap.top()); maxHeap.pop();
        }
    }
    
    double findMedian() {
        // TODO: Write your code here
        if(maxHeap.size() == minHeap.size())
            return maxHeap.top()/2.0 + minHeap.top()/2.0; //prevent overflow
        else
            return minHeap.top(); //if odd, number of minHeap more than maxHeap 
        
        return -1;

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

