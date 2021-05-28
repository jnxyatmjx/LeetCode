/*
 * @lc app=leetcode id=393 lang=java
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
class Solution {
    // This solution is shared from APAS. The highest rated coding interview algorithm learning APP on Android! Download it from here: https://goo.gl/YXD3m2
public boolean validUtf8(int[] data) {
  int count = 0;
  for (int c : data) {
    if (count == 0) 
    {
      if ((c >> 5) == 0b110) { // 2 bytes
        count = 1;
      } else if ((c >> 4) == 0b1110) { // 3 bytes
        count = 2;
      } else if ((c >> 3) == 0b11110) { // 4 bytes
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
// This solution is shared from APAS. The highest rated coding interview algorithm learning APP on Android! Download it from here: https://goo.gl/YXD3m2
}
// @lc code=end

