class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        stack<char> s1;
        s1.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(!s1.empty() && toupper(s1.top())==toupper(s[i]) && s1.top()!=s[i]){
                s1.pop();
            }
            else{
                s1.push(s[i]);
            }
        }

        while(!s1.empty()){
            ans += s1.top();
            s1.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};