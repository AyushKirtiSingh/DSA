class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int count = 0;
        int j=-1;
        for(int i=0;i<s.length();i++){
            
            string words = "";
            int count1 = 0;
            while(i<s.length() && s[i] != ' '){
                words += s[i];
                i++;
            }
            j++;
            if(j==0){
                for(int i=0;i<words.length();i++){
                    if(words[i]=='a' || words[i]=='e' || words[i]=='i' || words[i]=='o' || words[i]=='u'){
                        count++;

                    }
                }
            }
            else{
                for(int i=0;i<words.length();i++){
                    if(words[i]=='a' || words[i]=='e' || words[i]=='i' || words[i]=='o' || words[i]=='u'){
                        count1++;
                        
                    }
                    

                }
                if(count1==count){
                        reverse(words.begin(),words.end());
                }
            }
            ans += ' ' + words;

        }
        return ans.substr(1);
        
    }
};