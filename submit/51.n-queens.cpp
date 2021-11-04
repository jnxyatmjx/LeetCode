/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;

        /*
            initialize board. '.' means empty, 'Q' means a Queen
            board contain n rows and n columns
            one row default is all empty '.'
        */
        vector<string> board(n,string(n,'.'));
        backtrack(board,0,res);

        return res;
    }

    void backtrack(vector<string>& board,int row,vector<vector<string>>& res)
    {
        if(row == board.size())
        {
            res.push_back(board);
            return ;
        }

        size_t numofCells1row = board[row].size();
        for(size_t i=0;i<numofCells1row;i++)
        {   
            if(!isValid(board,row,i))
                continue;

            //make chance
            board[row].at(i) = 'Q';
            
            //enter next row
            backtrack(board,row+1,res);
            
            //cancel the chance
            board[row].at(i) = '.';
        }
        

    }//end backtrack

    /* is Queen valid at board[row][col] ?*/
    bool isValid(vector<string>& board, int row, int col) {
        
        int n = board.size();
        // check is same column
        /* no need to check row, because a row default is empty '.' */
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // check upper right area
        for (int i = row - 1, j = col + 1; 
                i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        // check upper left area
        for (int i = row - 1, j = col - 1;
                i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        
        return true;

    }//end isValid
};
// @lc code=end

