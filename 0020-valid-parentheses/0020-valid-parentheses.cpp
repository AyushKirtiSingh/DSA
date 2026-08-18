class Solution {
public:
    bool isValid(string s) {
        stack<char> m;
        for(int i=0;i<s.length();i++){
            // opening bracket ko stack me daalo
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                m.push(s[i]);
            }
            else{
                // closing bracket ke liye stack empty nahi hona chahiye
                if(m.empty()){
                    return false;
                }

                // top bracket ka matching pair check karo
                if(m.top()=='(' && s[i]==')' || m.top()=='[' && s[i]==']' || m.top()=='{' && s[i]=='}'){
                    m.pop();
                }
                else{
                    return false;
                }
            
            }
            
        }
        // agar stack empty hai to saare brackets match ho gaye
        return m.empty();
    }
};