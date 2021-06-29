/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        std::deque<char> stack_;//Use as stack

        for(auto const& c_:s)
        {
            if(c_=='(' || c_=='[' || c_=='{')
            {
                stack_.push_back(c_);
            }
            else if(c_==')' || c_==']' || c_=='}') //Pop the top stack and compare
            {
                if(stack_.empty()) return false;

                char tc = stack_.back();
                if( (tc=='('&&c_==')') || (tc=='{'&& c_=='}') || (tc=='['&& c_==']') )
                {
                    stack_.pop_back();
                }
                else
                    return false;
            }
            else //invalid character
                return false;
        }//end for

        return stack_.empty(); 
    }
};
// @lc code=end

