/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
class Solution {
public:
/*
    CAUTION
    0b --> binary
    0  --> octal
    0x --> hexadecimal

*/
    bool validUtf8(std::vector<int>& data_) {
        int count = 0;
        for (const int& c : data_) {
            if (count == 0) 
            {
                if ((c >> 5) == 0b110) { // 2 bytes
                    count = 1;
                } 
                else if ((c >> 4) == 0b1110) { // 3 bytes
                    count = 2;
                } 
                else if ((c >> 3) == 0b11110) { // 4 bytes
                    count = 3;
                } 
                else if ((c >> 7) > 0) // Most significant digit cannot be 1 if it''s not multiple bytes
                {
                    return false;
                }
            } 
            else 
            {
                if ((c >> 6) != 0b10) {
                    return false;
                }
                count--;
            }

    } //end for
        return count == 0;
    }
};
// @lc code=end

