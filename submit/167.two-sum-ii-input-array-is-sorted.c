/*
 * @lc app=leetcode id=167 lang=c
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){

    for(int i = 0; i < numbersSize; i++)
    {
        int l = i + 1, r = numbersSize - 1;
        int val = target - numbers[i];
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(numbers[mid] > val)
                r = mid - 1;
            else if(numbers[mid] < val)
                l = mid + 1;
            else
            {
                int * res = (int *)malloc(sizeof(int) * 2);
                memset(res,0,sizeof(int) *2);
                res[0] = i + 1;
                res[1] = mid + 1;
                *returnSize = 2;
                return res;
            }
        }//end while

    }//end for
    *returnSize = 0;
    return NULL;
}
// @lc code=end

