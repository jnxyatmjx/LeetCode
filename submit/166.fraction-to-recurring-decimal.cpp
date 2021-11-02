/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start

/*
    103993/33102
    104348/33215

*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return string("0");
        
        string fraction;
        if((numerator<0) != (denominator<0))
            fraction.append(1,'-');

        //caution overflow for int
        long dividend = static_cast<long>(numerator) * (numerator > 0 ? 1: -1);
        long divisor  = static_cast<long>(denominator) * (denominator > 0 ? 1: -1);

        fraction.append(to_string(dividend/divisor));

        long remainder = dividend % divisor;
        if(remainder == 0)
            return fraction;

        fraction.append(1,'.');

        map<long,size_t> contain;
        while(remainder != 0)
        {   
            if(contain.count(remainder) > 0)
            {
                fraction.insert(contain[remainder],1,'(');
                fraction.append(1,')');
                break;  
            }
            contain[remainder] = fraction.size();

            remainder *= 10;
            fraction.append(to_string(remainder/divisor));
            remainder %= divisor;
        }

        return fraction;
    }
};
// @lc code=end

