
    /*
    Time complexity : O(9^81)
    Space complexity : O(1)
    */


class Solution {
public:

bool valid(vector<vector<char>> &board, int row , int col, char c)
    {
        for(int i = 0 ; i < 9 ; i++)
        {
            if(board[i][col] == c) return false;
            if(board[row][i] == c) return false;
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) 
    {
        for(int i = 0 ; i < board.size() ; i++)
        {
            for(int j = 0 ; j < board[0].size() ; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char num = '1' ; num <= '9' ; num++)
                    {
                        if(valid(board,i,j,num)) 
                        {
                            board[i][j] =num;
                            if(solve(board) == true) return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;    
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        bool flag = solve(board);
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/sudoku-solver
    */

    