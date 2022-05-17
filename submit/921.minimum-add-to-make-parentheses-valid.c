/*
 * @lc app=leetcode id=921 lang=c
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start


int minAddToMakeValid(char * s){
    int lftpar=0, rgtpar=0; //number of left and right parenthesis needs
    int sl=strlen(s);
    
    for (int i=0; i<sl; i++)
    {
        if(s[i] == '(') //encount left, need plus 1 right bracket needs
            ++rgtpar;
        else if(s[i] == ')')
        {
            if(rgtpar > 0) //encount left before, just minus 1 right bracket needs
                --rgtpar;
            else
                ++lftpar; // never encount  left, just plus 1 left bracket needs
        }
    }

    return lftpar + rgtpar;
}
// @lc code=end

