* ### **背调**

1. 跟领导关系是否融洽

2. 工作中有没有负面情绪

3. 与团队关系怎么样

4. 业务技能 （中上等 ）

5. 抗压能力

6. 是否能按时完成工作任务

   

* ### **文件中有40亿个QQ号码，设计算法对QQ号码去重，相同的QQ号码仅保留一个，内存限制1G**

>1. hash map 自然去重，内存限制无法满足  (not ok)
>2. 排序 [解为多个文件然后用 合并排序或者桶排序]，排序后可以方便的去重。(not ok)
>3. bitmap QQ号码为非负正整数且有最大值(类似桶排序)，处理好后可直接作 去重 。
>4. 如果QQ号码均不相同 则可以作 top-K 排序使用。

* ### **在2.5亿个整数中找出不重复的整数，注，内存不足以容纳这2.5亿个整数**

>1. 采用2-Bitmap（每个数分配2bit，00表示不存在，01表示出现一次，10表示多次，11无意义）进行，共需内存$2^{32}\times2=1G$内存，还可以接受。然后扫描这2.5亿个整数，查看Bitmap中相对应位，如果是00变01，01变10，10保持不变。所描完事后，查看bitmap，把对应位是01的整数输出即可。
>2. 进行划分小文件的方法。然后在小文件中找出不重复的整数，并排序。然后再进行归并，注意去除重复的元素.

* ### **负数 --》取模 取余 的区别**

1. 取模 商趋向于 负无穷
2. 取余 商趋向于 正无穷



* ### **计算递归算法时间复杂度的方法，是找到递归深度，然后乘以每次递归中迭代的次数**



* ### **无序数组中找到$Kth$大(小)的值**

>1. 排序后找到$Kth$值 Time: $O(Nlog_2N)$
>2. 遍历数据同时放入堆 Time:$O(Nlog_2K)$
>3. [**快速选择**]  类似  [**快速排序**] 能以**最快$O(2N-1)$**,\[**最差$O(N^2)$有序数组**\]速度找打$Kth$值 (e.g.  215)






* ### 死锁及检测死锁
>1. 在MySQL中，当两个或两个以上的事务相互持有或者请求锁，并形成一个**循环的依赖关系**，就会产生死锁
>2. 两个或两个以上任务同时拥有并请求彼此的资源，请求时**形成一个循环依赖关系**，会产生死锁
>> 1. MySQL 的死锁检测算法是**深度优先搜索，如果在搜索过程中发现了环，就说明发生了死锁**. 为了避免死锁检测开销过大，如果搜索深度超过了 200（LOCK_MAX_DEPTH_IN_DEADLOCK_CHECK)也同样认为发生了死锁。[e.g. [here](https://leviathan.vip/2020/02/02/mysql-deadlock-check/)]
>> 2. InnoDB 使用 MVCC 来解决事务的并发控制，而其中 Undo Log 是 MVCC 的重要组成部分




* ### 回溯及操作步骤
1. 在选项集合中遍历选项
2. 做出选择
3. 递归操作
4. 撤销选择
>- array `nums` of distinct integers, return *all the possible permutations*.**46**
>```c++
  vector<vector<int>> permute(vector<int>& num) {
          vector<vector<int>> res;
          vector<int> out, visited(num.size(), 0);
          backtrack(num, 0, visited, out, res);
          return res;
      }
      void backtrack(vector<int>& num, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
          //level is recored current number of visited
          if (level == num.size()) {
                  res.push_back(out); 
                  return;
              }
          for (int i = 0; i < num.size(); ++i) {
              if (visited[i] == 1) //position of num array
                  continue;
              visited[i] = 1;
              out.push_back(num[i]); //make a choice
              backtrack(num, level + 1, visited, out, res);
              out.pop_back(); //cancel the choice
              visited[i] = 0;
          }//end for
      }
  ```
------
------
>- integers `n` and `k`, return *all possible combinations of* `k` *numbers out of the range* `[1,n]`.**77**
>```c++
vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out;
        backtrack(res,out,1,n,k);//start from 1, [1,....,n]
        return res;
    }
    //Have n select options(n width of decision tree), 
    //k heigh of decision tree
    void backtrack(vector<vector<int>>&res ,vector<int>&out,int start, int n,int k)
    {
        if(static_cast<int>(out.size()) == k)//bottom of decision tree
        {
            res.push_back(out);
            return ;
        }
        for(int i=start; i<=n; i++)
        {
            out.push_back(i);//make a choice
            backtrack(res,out,i+1,n,k);
            out.pop_back();
        }
    }//end backtrack;
  ```
------
------
>- array `nums` of distinct elements, return *all possible subsets (the power set)*.**78**
>```c++
vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() <= 0)
            return vector<vector<int>>();
        vector<vector<int>> res;
        vector<int> out;
        bt(nums,res,out,0);
        return res;
    } //end subsets
    void bt(vector<int>& nums,vector<vector<int>>& res,vector<int>& out,int start)
    {
        //this maybe a NULL set ??
        res.push_back(out); //Why and WF?????
        for(int i=start; i<nums.size(); i++)
        {
            out.push_back(nums[i]);
            bt(nums,res,out,i+1);
            out.pop_back();
        }
    }
  ```





* ###二分查找及变种
- 普通二分查找
- 查第一个二分查找
- 查最后一个二分查找
>- search normal
> ```c++
int Binary_normal(int*num,int tar,int lef ,int rig)
{   
    while(lef <= rig)
    {
        int mid = lef + (rig-lef)/2;//prevent overflow
        if(num[mid] > tar)
            rig = mid - 1;
        else if(num[mid] < tar)
            lef = mid + 1;
        else
        	return mid;
    }
    return -1;
}
------
------
>- search first
>```c++
>int Binary_first(int*num,int tar,int lef ,int rig)
>{   
>  while(lef <= rig)
>  {
>      int mid = lef + (rig-lef)/2;
>      if(num[mid] > tar)
>          rig = mid - 1;
>      else if(num[mid] < tar)
>          lef = mid + 1;
>      else
>      {
>          //get the first when find equal elements
>          if(mid==lef || num[mid-1]!=tar) return mid;
>          rig = mid -1;
>      }
>  }
>  return -1;
>}
------
------
>- search last
>```c++
>int Binary_last(int*num,int tar,int lef ,int rig)
>{   
>  while(lef <= rig)
>  {
>      int mid = lef + (rig-lef)/2;
>      if(num[mid] > tar)
>          rig = mid - 1;
>      else if(num[mid] < tar)
>          lef = mid + 1;
>      else
>      {
>          //get last when find equal elements
>          if(mid==rig || num[mid+1]!=tar) return mid;
>          lef = mid +1;
>      }
>  }
>  return -1;
>}





* ###  Binary Tree二叉树
> - **Unique BST**.Integer `N`, return the number of **unique BST's**  which has exactly n nodes of unique values **from 1 to `N`**.96
> ```c++
> int numTrees(int n) {
>         vector<vector<int>> // value from 1 to n ,so we need n+1 vector size
>             dp(n+1,vector<int>(n+1,0));//dynamic programming去重备忘录
> 
>         //it is arranged in order from 1 to n, which ensure a BST can be constructed
>         return nums(1,n,dp);
>     }
> int nums(int lft, int rgt,vector<vector<int>>& dp)
> {
>     if(lft > rgt) return 1;//1 for multiply
> 
>     if(dp[lft][rgt] != 0) return dp[lft][rgt];
> 
>     int res=0;
>     for(int i=lft; i<=rgt; i++)
>     {
>         //i as root for this psuedo-subtree
>         int left = nums(lft,i-1,dp);
>         int right = nums(i+1,rgt,dp);
>         res += left * right;      //calculate them separately and add them
>     }
>     dp[lft][rgt] = res; //like post traversal tree
>     return res;
> }



> - **Unique BST II**.Integer `N`, return ***all  unique BST**'s, which has exactly* `n` *nodes of unique values from* `1` *to* `N`. 95
> ```c++
> vector<TreeNode*> generateTrees(int n) {
>        return build(1,n);
>     }
> 
> vector<TreeNode*> build(int lft, int rgt)
> {
>     if(lft>rgt) return {NULL};//for NULL node
> 
>     vector<TreeNode*> res;
> 
>     for(int i=lft; i<=rgt; i++)
>     {
>         vector<TreeNode*> left  = build(lft,i-1);
>         vector<TreeNode*> right = build(i+1,rgt);
> 
>         for(auto l:left)
>             for(auto r:right)
>             {
>                 TreeNode* root = new TreeNode(i);//i as root node of subtree
>                 root->left = l;
>                 root->right = r;
>                 res.push_back(root);
>             }
>     }
>     return move(res);//like post order traversal
> }



> - **Maximum Binary Tree**.Integer array `nums` with no duplicates. Return *the **maximum binary tree** built from* `nums` .654
>
> ```c++
> TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
>         TreeNode * root = helper(nums,0,static_cast<int>(nums.size())-1);
>         return root;
>     }
> 
>     TreeNode* helper(vector<int>& nums,int lft,int rgt)
>     {
>         if(lft > rgt) return NULL;
>         
>         int maxv=nums[lft], idx=lft;
>         for (int i=lft; i<=rgt; i++) //find maximum value from lft to rgt
>         {
>             if(nums[i] > maxv)
>             {
>                 maxv = nums[i];
>                 idx = i;
>             }
>         }
> 
>         TreeNode * root = new TreeNode(maxv);
>         root->left = helper(nums,lft,idx-1);
>         root->right = helper(nums,idx+1,rgt);
> 
>         return root;
>     }



> - Determine a binary  tree is a valid binary search tree (BST).98
>
>   ```c++
>   /*
>   	Subtree with node root as its root.
>   	min--> Subtree of node root's minimum value node
>   	max--> Subtree of node root's maximum value node
>   */
>   bool preorder_traver(struct TreeNode* root,struct TreeNode* min,struct TreeNode* max)
>   {
>       if(root==NULL) return true;
>     
>       if(min && root->val <= min->val) return false;
>       if(max && root->val >= max->val) return false;
>   	/*
>   		root as Left(root->left) subtree's maximum value node
>   		root as Right(root->right) subtree's minimum value node
>       */
>       return preorder_traver(root->left,min,root) && 
>              preorder_traver(root->right,root,max);
>   }
>     
>   bool isValidBST(struct TreeNode* root){
>     
>       return preorder_traver(root,NULL,NULL);
>   }
>   ```



> - Given a **binary tree** `root`, return *the maximum sum of all keys of **any** sub-tree which is also a Binary Search Tree (BST)*.1373
>
> ```c++
> #define maxl(a,b)\
> ({ __typeof__ (a) a_ = (a);\
>     __typeof__ (b) b_ = (b);\
>     a_ > b_ ? a_ : b_;})
> 
> struct context
> {
>     bool isBST;
>     int min; //minimum node of this tree(means this tree's minimum node)
>     int max; //maximum node of this tree(means this tree's maximum node)
>     int sum; //this tree's(if is a BST) sum of nodes
> };
> 
> struct context dfs(struct TreeNode* root,int *maxsum)
> {
>     ////make sure a leaf is BST
>     //this is a NULL pseudo-node,make sure its parent node(a leaf node) process condition
>     // --> root->val > left.max && root->val < right.min
>     if(root == NULL)
>     {
>         struct context temp = {true,40001,-40001,0};
>         return temp;
>     }
> 
>     struct context left = dfs(root->left,maxsum);
>     struct context right = dfs(root->right,maxsum);
> 
>     if(left.isBST==false || right.isBST==false ||
>         root->val <= left.max || root->val >= right.min)
>         /*root->val > left.max and root->val < right.min is BST*/
>     {
>         struct context temp = {false,0,0,0};
>         return temp;
>     }
> 
>     struct context temp;
>     temp.isBST = true;
>     temp.min = (root->left ? left.min : root->val);   //if has left subtree, set left subtre's min as total tree's minimum val
>     temp.max = (root->right ? right.max : root->val); //if has right subtree, set right subtree's max as total tree's maximum val
>     temp.sum = root->val + left.sum + right.sum;
>     *maxsum = maxl(*maxsum,temp.sum);
> 
>     return temp;
> }
> //[4,3,null,1,2]
> int maxSumBST(struct TreeNode* root){
>     
>     // Must initial a values or will get a wrong value
>     // Example 3,All values are negatives. Return an empty BST.
>     int maxSUm = 0;
>     dfs(root,&maxSUm);
>     
>     return maxSUm;
> }
> ```