class Solution {
public:
    bool issafe(vector<string> &board,int row,int col,int n){  //O(n)
        //vertical
        for(int i=0;i<n;i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }                               //first two loops for same row and column

        //horizontal
        for(int j=0;j<n;j++){
            if(board[row][j] == 'Q'){
                return false;
            }                           //TIME COMPLEXITY : O(n!)
        } 

        //left diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }                           //next two loops for diagonals
        }

        //right diagonal
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        return true;
    }

    void nqueens(vector<string> &board,int row,int n, int &ans){
        if(row==n){
            ans++;    //base case where ans is incremented for every valid placement of Q.
            return;    //it will return back to the function to then do the backtracking
        }

        for(int j=0;j<n;j++){
            if(issafe(board,row,j,n)){
                board[row][j] = 'Q';     //include
                nqueens(board,row+1,n,ans);
                board[row][j] = '.';     //backtracking
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        int ans = 0;

        nqueens(board,0,n,ans);

        return ans;
    }
};