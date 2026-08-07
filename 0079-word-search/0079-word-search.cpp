class Solution {
public:
    bool wordsearch(vector<vector<char>>& board, string word,int r,int c,int i){
        int n = board.size();
        int m = board[0].size();
        if(r<0 || c<0 || r>=n || c>=m || board[r][c]==-1 || board[r][c]!=word[i]){
            return false;
        }

        if(i == word.length()-1){
            return true;
        }

        char temp = board[r][c];

        board[r][c] = '#';  //visit

        bool ans1 = wordsearch(board,word,r+1,c,i+1);  //down
        bool ans2 = wordsearch(board,word,r-1,c,i+1);  //up
        bool ans3 = wordsearch(board,word,r,c+1,i+1);  //right
        bool ans4 = wordsearch(board,word,r,c-1,i+1);  //left

        board[r][c] = temp;  //unvisit

        return (ans1 || ans2 || ans3 || ans4);

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(wordsearch(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};