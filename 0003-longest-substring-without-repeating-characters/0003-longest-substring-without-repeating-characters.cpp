class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxval = INT_MIN;
        if(s.length()==0){
            return 0;
        }
        for(int i=0;i<s.length();i++){
            string ans = "";
            int count = 0;
            for(int j=i;j<s.length();j++){
                if(ans.find(s[j])==string::npos){
                    ans += s[j];
                    count ++;
                    maxval = max(maxval,count);
                }
                else{
                    break;
                }
            }
        }
        return maxval;
    }
};