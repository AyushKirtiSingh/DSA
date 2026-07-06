class Solution {
public:
    int rev(string s){
        string ans;
        for(int i=s.length()-1;i>=0;i--){
            ans += s[i];

        }
        int result = stoi(ans);
        return result;
    }
    
    int mirrorDistance(int n) {
        string str = to_string(n);
        int reverse = rev(str);
        return abs(n-reverse);
        
    }
};