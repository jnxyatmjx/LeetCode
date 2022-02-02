/*
 * @lc app=leetcode id=287 lang=c
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start


int findDuplicate(int* nums, int numsSize){

/*Below is Time Limit Exceeded*/
    /*for(int i=1; i<numsSize; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(nums[i]==nums[j])
                return nums[i];
        }
    }
    return -1;*/

//Below is allmost Mathmatic 
//But [1,2,3,4,5,4,4] is error
    // long Sumarr = 0;
    // for(int i=0; i<numsSize; i++)
    //     Sumarr+= nums[i];
    
    // long neres = (numsSize-1)*numsSize/2;
    
    // return Sumarr-neres;

    //Fix length arr to store the frequency, since it's from 1 to n, use index as val and number in the arr is frequency
    //But space O(N)
    int out = 0;
    int * ptr = calloc(sizeof(int), numsSize);
    for (int i = 0; i < numsSize; i++){
        ptr[nums[i]] +=1;
        
        if(ptr[nums[i]] == 2){
            return nums[i];
            
        }
    }
    return -1;

}
// @lc code=end

