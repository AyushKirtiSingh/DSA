class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length();
        bool flag = true;
        int ans = 0;

        while(i--){
            if(flag==true && s[i] == ' '){
                continue;
            }

            else if(s[i]!=' '){
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