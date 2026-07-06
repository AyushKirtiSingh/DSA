class Solution {
public:
    bool detectCapitalUse(string word) {
        bool ans = false;
        for(int i=0;i<word.length();i++){
            if(isupper(word[i])!=0){
                ans = true;
            }
            else{
                ans = false;
                break;
            }
        }

        if(ans==false){
            for(int i=0;i<word.length();i++){
                if(isupper(word[i])==0){
                    ans = true;
                }
                else{
                    ans = false;
                    break;
                }
            }
        }

        if(ans==false){
            for(int i=1;i<word.length();i++){
                if(isupper(word[0])!=0 && i!=0 && isupper(word[i])==0){
                    ans = true;
                }
                else{
                    ans = false;
                    break;
                }
            }

        }
        

        return ans;
        
        
    }
};