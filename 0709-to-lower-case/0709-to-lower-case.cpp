class Solution {
public:
    string toLowerCase(string s) {
        string str = "";
        for(int i=0;i<s.length();i++){
            str += tolower(s[i]);

        }
        return str;
        
    }
};