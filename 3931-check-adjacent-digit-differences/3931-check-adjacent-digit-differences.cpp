class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        bool ans;
        for(int i=0;i<s.length()-1;i++){
            if(abs(s[i]-s[i+1]) <= 2){
                ans = true;
            }
            else{
                ans = false;
                break;
            }
        }
        return ans;
        
    }
};