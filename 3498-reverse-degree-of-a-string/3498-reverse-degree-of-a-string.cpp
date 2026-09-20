class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i=0;i<s.length();i++){
            int rev = 0;
            rev = 26-(s[i]-'a');
            sum += (rev*(i+1));
        }

        return sum;
    }
};