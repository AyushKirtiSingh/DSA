class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());      //reverses entires string
        string ans = "";

        for(int i=0;i<s.length();i++){          //used to get each words indivdually
            string words = "";
            while(i<s.length() && s[i]!=' '){
                words += s[i];
                i++;
            }

            reverse(words.begin(),words.end());      //reverse the individual words
            if(words.length()>0){
                ans += " " + words;       //add it in the ans with a space from starting
            }
        }

        return ans.substr(1);         //used to avoid the first space at index 0
        
    }
};