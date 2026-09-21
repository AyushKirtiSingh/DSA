class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";
        int count = 0;

        int i=0;

        while(i<s.length()){
            string temp = "";
            while(s[i]!=' ' && i<s.length()){
                temp += s[i];
                i++;
            }
            ans += temp;
            
            count++;

            i++;

            if(count==k){
                break;
            }
            ans += ' ';

        }

        return ans;
        
    }
};