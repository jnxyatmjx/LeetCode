/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */

// @lc code=start
class Solution {
public:
/*
    bool isValidSerialization(string preorder) {
        int capacity = 1;
        preorder += ",";
        for (int i = 0; i < preorder.size(); ++i) {
            if (preorder[i] != ',') continue;
            if (--capacity < 0) return false;
            if (preorder[i - 1] != '#') capacity += 2;
        }
        return capacity == 0;
    }
*/
    //Use binary tree deserialize recursive
    bool isValidSerialization(string preorder)
    {
        vector<string> ordervec;
        split(preorder,',',ordervec);
        
        size_t idx = 0;
        bool isva = true;
        prebuild(ordervec,&idx,&isva);

        //if preorder recursive is over end eg. (9,#,#,1). But ordervec still have values
        if(idx < ordervec.size())
            isva = false;

        return isva;
    }

    void prebuild(vector<string>& orderv,size_t * idx,bool* isval)
    {
        if(*idx >= orderv.size()) //error
        {
            *isval = false;
            return;
        }

        if(orderv[*idx].compare("#") == 0)
        {
            *idx +=1;
            return ;
        }
        *idx +=1;
        prebuild(orderv,idx,isval);
        prebuild(orderv,idx,isval);
    }

    void split(const string &s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }
};
// @lc code=end