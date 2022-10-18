/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 */

// @lc code=start
class Solution {
public:
    int lastRemaining(int n) {

        int step = 1, res = 1;
        while (step * 2 <= n) {
            res += step;
            step *= 2;
            if (step * 2 > n) break;
            if ((n / step) % 2 == 1) res += step;
            step *= 2;
        }
        return res;
/*
如果仔细观察，可以发现从左往右删的时候，每次都是删掉第一个数字，而从右往左删的时候，则有可能删掉第一个或者第二个数字，而且每删一次，数字之间的距离会变为之前的两倍。
这里要做的是每次记录当前数组的第一个数字，而且再通过观察可以看出，从右往左删时，如果剩下的数字个数是偶数个时，删掉的是第二个数字；如果是奇数个的时候，删掉的是第一个数字。
总结出了上述规律，就可以写出以上代码:
*/
    /* this solution is error
        if(n==1) return 1;
        std::vector<int> res;
        std::vector<int> tmp;
        for(int i=1; i<=n; i++){
            res.push_back(i);
        }
        while(res.size() > 0){
            for(std::size_t i=0; i<res.size(); i++){
                if(i+1 < res.size())
                    tmp.insert(tmp.begin(),res[i+1]);
                i++;
            }
            res.clear();

            for(std::size_t i=0; i<tmp.size(); i++){
                if(i+1 < tmp.size())
                    res.insert(res.begin(),tmp[i+1]);
                i++;
            }

            if(tmp.size() > 1) tmp.clear();
        }

        //printf("rse:%td tmp:%td tmp[0]:%d\n",res.size(),tmp.size(),tmp[0]);
        return tmp[0];
        */
    }
};
// @lc code=end

