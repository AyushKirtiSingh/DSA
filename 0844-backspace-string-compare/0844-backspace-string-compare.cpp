class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>s2;

        for(char c : s){
            if(c=='#' && !s1.empty()){
                s1.pop();
            }
            else if(c=='#' && s1.empty()){
                continue;
            }
            else{
                s1.push(c);
            }
        }

        for(char c : t){
            if(c=='#' && !s2.empty()){
                s2.pop();
            }
            else if(c=='#' && s2.empty()){
                continue;
            }
            else{
                s2.push(c);
            }
        }

        string ans1 = "";
        string ans2 = "";

        while(!s1.empty()){
            ans1 += s1.top();
            s1.pop();
        }

        while(!s2.empty()){
            ans2 += s2.top();
            s2.pop();
        }

        if(ans1==ans2){
            return true;
        }
        else{
            return false;
        }
        
    }
};