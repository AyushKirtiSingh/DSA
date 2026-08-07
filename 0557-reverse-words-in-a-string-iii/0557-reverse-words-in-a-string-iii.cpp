class Solution {
public:
    string reverseWords(string s) {
        string ans = "";

        for(int i=0;i<s.length();i++){
            string words = "";
            while(i<s.length() && s[i]!=' '){
                words += s[i];     //it is used to get each word individually
                i++;
            }
            reverse(words.begin(),words.end());   //reverses the individual words

            ans += ' ' + words;   //then adding the words in ans with a single space
        }

        return ans.substr(1);   //it will ignore the first space of the string
        
    }
};