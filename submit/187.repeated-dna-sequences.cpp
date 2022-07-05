/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences1(string s) {
        std::vector<std::string> res;

        set<string> seend;
set<string> seeres;
        for (size_t i=0; i+10<=s.length(); i++)
        {
            std::string subs = s.substr(i,10);
            if(seend.count(subs) > 0)
                seeres.insert(subs);
            
            seend.insert(subs);

        }
        //remove duplicate elements
        return std::vector<std::string>(seeres.begin(),seeres.end());
    }

    vector<string> findRepeatedDnaSequences(string s){
        vector<int> isdna(s.length(),0);
   
        for(size_t i=0; i<s.length(); i++)
        {
            switch (s.at(i))
            {
                case 'A':
                    isdna[i] = 0;
                    break;
                case 'C':
                    isdna[i] = 1;
                    break;
                case 'G':
                    isdna[i] = 2;
                    break;
                case 'T':
                    isdna[i] = 3;
                    break;
                default:
                    break;
            }
        } // end hash letter to number

        set<string>res;
        set<int> seen;

        int lft=0, rgt=0;
        int mulsum=0;
        while(rgt < isdna.size())
        {   
            //sliding windows right
            mulsum = mulsum*4 + isdna[rgt];/*decimal representation of the Quadratic number*/
            rgt++;

            if(rgt-lft == 10)
            {

                if(seen.count(mulsum))
                    res.insert(s.substr(lft,rgt-lft));
                
                seen.insert(mulsum);
                
                //sliding windows left
                mulsum -= isdna[lft]*(1<<18);
                lft++;
            }
        }

        return vector<string>(res.begin(),res.end());
    }
};
// @lc code=end

