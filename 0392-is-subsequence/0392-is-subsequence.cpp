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

        if(s.length()==0){
            ans = true;
        }
        if(t.length()==0){
            ans = false;
        }

        if(s.length()>t.length()){
            ans = false;
        }

        if(s.length()==0 && t.length()==0){
            ans = true;
        }

        return ans;
        
    }
};