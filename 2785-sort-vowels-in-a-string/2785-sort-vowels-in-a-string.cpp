class Solution {
public:
    string sortVowels(string s) {
        vector<char> ans;
        for(char x : s){
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||x=='A'||x=='E'||x=='I'||x=='O'||x=='U'){
                ans.push_back(x);
            }
            
        }

        sort(ans.begin(),ans.end());


        int idx = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O' && s[i]!='U'){
                continue;
            }
            else{
                s[i] = ans[idx];
                idx++;
            }
        }
        return s;
        
        
    }
};