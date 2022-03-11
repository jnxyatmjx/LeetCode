/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        quick_sock2(nums,0,static_cast<int>(nums.size())-1,k);
        return nums[k-1];
    }

//Decrease Sort
void quick_sock2(vector<int>& a, int lft, int rgt,int k)
{
    if(lft >= rgt) return;
    int i=lft-1, j=rgt, pivot=a[rgt];

    while(1)
    {
        while (a[++i] > pivot) //equal to pivote, stop i, swap i,j
            if(i >= rgt) 
                break;
        
        while (a[--j] < pivot) //when equal to pivote, stop j, swap i,j
            if(j <= lft) 
                break;
        
        if(i<j)
            swap(a[i],a[j]);
        else
            break;
    }//end while

    //set pivote to right position i
    swap(a[i],a[rgt]);


    //Decreasing array. the more forward, the bigger
    if(k < i+1) //
        quick_sock2(a,lft,i-1,k);
    else if(k > i+1)
        quick_sock2(a,i+1,rgt,k);
}

//Increase Sort
void quick_sock1(vector<int>& a, int lft, int rgt, int k)
{
    if(lft >= rgt) return;
    int i=lft, j=rgt+1, pivot=a[lft];
    
    while(1)
    {
        while(a[++i]<pivot) //when equal to pivot stop i, swap i,j
            if(i>=rgt)
                break;
        
        while(a[--j]>pivot) //when equal to pivot stop j, swap j,i
            if(j<=lft)
                break;

        if(i < j)
            swap(a[i],a[j]);
        else
            break;
        
    }//end while

    //set pivot to right position
    swap(a[j],a[lft]);

    quick_sock1(a,lft,j-1,k);
    quick_sock1(a,j+1,rgt,k);
}

//minHeap with k elements
std::priority_queue <int ,std::vector<int>, std::greater<int>> minHeap;
};
// @lc code=end

