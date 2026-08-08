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
            }                 //the main problem i got stuck was to find the first word for that took another variable j to check that and initialized before for loop so it never resets.
            j++;
            if(j==0){
                for(int i=0;i<words.length();i++){
                    if(words[i]=='a' || words[i]=='e' || words[i]=='i' || words[i]=='o' || words[i]=='u'){
                        count++;   //first word vowel count and stored forevers not resets for different i.

                    }
                }
            }
            else{
                for(int i=0;i<words.length();i++){
                    if(words[i]=='a' || words[i]=='e' || words[i]=='i' || words[i]=='o' || words[i]=='u'){
                        count1++;   //count of vowels of other words and it always resets for each value of i
                        
                    }
                    

                }
                if(count1==count){   //comparing the vowel count na dperforming operation
                        reverse(words.begin(),words.end());
                }
            }
            ans += ' ' + words;   //after the legal operation adding in new string with a space

        }
        return ans.substr(1);   //to remove the initial space in the ans
        
    }
};