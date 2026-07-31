class Solution {
public:
    bool issafe(vector<vector<char>>& board,int row,int col,int dig){
        char ch = dig + '0';
        //horizontal
        for(int j=0;j<9;j++){
            if(board[row][j]==ch){
                return false;
            }
        }                            //these two loops check for element in same row or col
        //vertical
        for(int i=0;i<9;i++){
            if(board[i][col]==ch){
                return false;
            }
        }
        //3X3 grid condition
        int startrow = (row/3)*3;
        int startcol = (col/3)*3;       //this checks whether same char is not in same grid 
        for(int i=startrow;i<startrow + 3;i++){
            for(int j=startcol;j<startcol + 3;j++){
                if(board[i][j]==ch){
                    return false;
                }
            }
        }
        return true;

    }

    bool helper(vector<vector<char>>& board,int row,int col){
        if(row==9){
            return true;   //base case and return helps to return back to funcn for backtracking
        }
        int nextrow = row, nextcol = col + 1;
        if(col>8){
            nextrow = row + 1;    //while traversing when moving to next row after col traversal
            nextcol = 0;
        }

        if(board[row][col]!='.'){    //if it contains char before then move to next cell
            return helper(board,nextrow,nextcol);
        }

        //place the digits

        for(int dig=1;dig<=9;dig++){
            if(issafe(board,row,col,dig)){
                char cw = dig + '0';
                board[row][col] = cw;      //it assings the element to safe place in char form
                if(helper(board,nextrow,nextcol)){ //include
                    return true;
                }
                board[row][col] = '.';  //backtracking if the above statement is false
            }
        }
        return false;

        
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);     //just call the function no need to return as funcn is void
    }
};