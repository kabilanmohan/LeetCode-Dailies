
    /*
    Time complexity : O(n * n!)
    Space complexity : O(n^2)
    */


class Solution {
public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.')); // nxn board with '.'
        int ans = 0;
        func_nqueens(n,board,ans,0);
        return ans;
    }
    
    bool check_valid(vector<string>& board , int row , int col , int n)
    {
        for(int i = 0; i < n ; i++)
        {
            // checking for another Queen in same row
            if(board[row][i] == 'Q' && (i != col)) return false;

            // checking for another Queen in same col
            if(board[i][col] == 'Q' && (i != row)) return false;

            // left diagonal check
            if(((row - i) >=0) && ((col - i)>=0))
            {
                if(board[row-i][col-i] == 'Q') return false;
            }

            //right diagonal check
            if(((row + i) < n) && ((col - i) >= 0))
            {
                if(board[row+i][col-i] == 'Q') return false;
            }
        }
        return true;
    }
    void func_nqueens(int n , vector<string>& board , 
    int &ans , int col)
    {
        // last function call filled last column and called n+1 ,hence append to answer
        if(col == n)
        {
            ans++;
            return;
        }

        // iterating through rows a given column
        for(int i = 0 ; i < n ; i++)
        {
            // check if we can place a queen in that spot
            if(check_valid(board,i,col,n))
            {
                // if yes, place the queen and call the function for next column
                board[i][col] = 'Q';
                func_nqueens(n,board,ans,col+1);
                // when backtracking after the function empty the queen filled spot
                board[i][col] = '.';
            }
        }
        // if no queens can be placed in that entire column , return
        return;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/n-queens-ii/
    */

    