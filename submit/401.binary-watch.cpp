/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
class Solution {
private:
    //combination calculate formula
    void getDigit(const std::vector<int>& vec,int turnNum,int posi,int sum,std::vector<int>& res)
    {	if(turnNum == 0)
        {
            res.push_back(sum);
            return ;
        }
        for(int i = posi; i < vec.size();i++)
            getDigit(vec,turnNum - 1,i + 1,sum + vec[i],res);
    }

    std::vector<int> getTok(const std::vector<int>& vec,int turnNum)
    {

        std::vector<int> res;
        getDigit(vec,turnNum,0,0,res);

        // for(const auto & m : res)
        // 	printf("%d ",m);
        // printf("\n");

        return res;
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        std::vector<int> a = {8,4,2,1};
        std::vector<int> b = {32,16,8,4,2,1};
        
        std::vector<std::string> res;

        for(int i = 0; i <= turnedOn; i++)
        {
            /*
                if the first line have i turns ,
                so the second line must have (turnedOn - i)
            */
            std::vector<int> led1 = getTok(a,i);	
            std::vector<int> led2 = getTok(b,turnedOn - i);

            for(const auto & l1 : led1)
            {
                if(l1 >= 12) continue;
                for(const auto & l2 : led2)
                {
                    if(l2 >= 60) continue;
                    std::string rval = std::to_string(l1) + ":" + (l2 < 10 ? "0" + std::to_string(l2) : std::to_string(l2));
                    //res.insert(res.begin(),rval);
                    res.push_back(rval);
                }
            }//end led1
        }

        return res;
    }
};
// @lc code=end

