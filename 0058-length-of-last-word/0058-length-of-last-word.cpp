class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length();
        int ans=0;
        bool flag= true;
        while(i--){

            if(flag==true && s[i] == ' '){
                continue;
            }
            if(s[i] != ' '){
                flag = false;
                ans++;
            }
            else{
                break;
            }
        }

        return ans;
    }
};