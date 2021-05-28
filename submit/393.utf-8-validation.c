/*
 * @lc app=leetcode id=393 lang=c
 *
 * [393] UTF-8 Validation
 */

// @lc code=start

/*
    0b --> binary
    0x --> hexadecimal
    0  --> octal
*/
bool validUtf8(int* data, int dataSize){
    int coutn = 0;
    for(int i = 0; i < dataSize; i++)
    {
        if(coutn == 0)
        {
            if( (data[i] >> 5) == 0b110) // two bytes
                coutn = 1;                              //total 2 bytes ,left 1 bytes need to process
            else if( (data[i] >> 4) == 0b1110) // three bytes
                coutn = 2;                              //total 3 bytes ,left 2 bytes need to process
            else if( (data[i] >> 3) == 0b11110)  //four bytes
                coutn = 3;                              //total 4 bytes ,left 3 bytes need to process
            else if( (data[i] >> 7) > 0)// one byte's Most Significant is 0
                return false;
        }//end coutn == 0
        else
        {
            if( (data[i] >> 6) != 0b10)
                return false;
            coutn--;
        }
    }//end for

    return coutn == 0;
}
// @lc code=end

