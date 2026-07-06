class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        int count = 0;
        bool ans = true;

        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                if(allowed.find(words[i][j])!=string::npos){
                    ans = true;
                }
                else{
                    ans = false;
                    break;
                }
            }
            if(ans){
                count++;
            }
        }
        return count;
        
    }
};