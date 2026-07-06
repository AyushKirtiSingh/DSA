class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        bool ans = true;
        int pos = 0;
      

        for(int i=0;i<s.length();i++){
            int idx = t.find(s[i], pos);
            if(t.find(s[i],pos)==string::npos){
                ans = false;
                
                break;
            }
            else{
                
                pos = idx + 1;
            }
        }
        return ans;
        
    }
};