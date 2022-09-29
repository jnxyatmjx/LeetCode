/*
 * @lc app=leetcode id=1343 lang=c
 *
 * [1343] Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 */

// @lc code=start

//sliding windows
int numOfSubarrays(int* arr, int arrSize, int k, int threshold){
    int res=0;
    int st = 0;
    int sum = 0;
    for(int ed=0; ed < arrSize; ed++){
        sum += arr[ed];
        if(ed - st >= k-1){ //slide window of size k
            if(sum / k >= threshold) res++;
            sum -= arr[st];
            st++;
        }
    }
    return res;
}
// @lc code=end

