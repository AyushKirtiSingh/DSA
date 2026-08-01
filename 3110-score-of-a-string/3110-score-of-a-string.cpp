class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for(int i=0;i<s.length()-1;i++){
            int sub = 0;
            char ch1 = s[i] - '0';
            char ch2 = s[i+1] - '0';
            sub = abs(ch1-ch2);
            sum += sub;

        }
        return sum;
        
    }
};