class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()>0 && s.find(part)<s.length()){     //when string is completely removed or substring is not found

            s.erase(s.find(part),part.length());     // erases element from starting position of find function till length of substring found
        }

        return s;
        
    }
};