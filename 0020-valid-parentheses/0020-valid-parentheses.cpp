class Solution {
public:
    bool isValid(string s) {
        stack<char> m;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                m.push(s[i]);
            }
            if(m.empty()){
                return false;
            }
            else if (s[i]==')' || s[i]==']' || s[i]=='}'){
                if(m.top()=='(' && s[i]==')' || m.top()=='[' && s[i]==']' || m.top()=='{' && s[i]=='}'){
                    m.pop();
                }
                else{
                    return false;
                }
            }
            
            
        }
        return m.empty();
    }
};