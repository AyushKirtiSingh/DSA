class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxval = 0;
        for(int i=0;i<sentences.size();i++){
            int count = 1;
            for(int j=0;j<sentences[i].length();j++){
                if(sentences[i][j]==' '){
                    count++;
                }
                
            }
            maxval = max(count,maxval);
        }
        return maxval;
        
    }
};