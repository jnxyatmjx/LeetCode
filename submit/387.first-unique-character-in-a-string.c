/*
 * @lc app=leetcode id=387 lang=c
 *
 * [387] First Unique Character in a String
 */

// @lc code=start

/*
    Simiar to is unique character

class Solution:
  def isUnique(self, astr: str) -> bool:
    mark = 0
    for char in astr:
      move_bit = ord(char) - ord('a')
      if (mark & (1 << move_bit)) != 0:
        return False
      else:
        mark |= (1 << move_bit)
    return True

作者：zhen-zhu-hao-hao-chi
链接：https://leetcode-cn.com/problems/is-unique-lcci/solution/wei-yun-suan-fang-fa-si-lu-jie-shao-by-zhen-zhu-ha/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

int firstUniqChar(char * s){
    
    int resId = -1;
    
    //symbol_idx : can save character and its number of occurrences 
    //value : save number of character occurrences in s 
    //index : offset length of character 'a'

    int * symbol_idx = (int*)malloc(26*sizeof(int));memset(symbol_idx,0,26*sizeof(int));
    size_t sLen = strlen(s);

    for(size_t i=0; i<sLen; i++)
    {
        size_t offLe = s[i] - 'a';
        symbol_idx[offLe]++;
    }

    //for(size_t i=0; i<26; i++)
    //    printf("%c-%d ",'a'+i,symbol_idx[i]);
    
    for(size_t i=0; i<sLen; i++)
    {
        if(symbol_idx[s[i]-'a'] == 1 )
        {
          resId = i;
          break;
        }
    }

    //release resource
    if(symbol_idx){ free(symbol_idx); symbol_idx=NULL; }

    return resId;
}
// @lc code=end

