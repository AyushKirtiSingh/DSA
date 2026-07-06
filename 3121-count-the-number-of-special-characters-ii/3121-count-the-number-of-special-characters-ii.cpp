class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s(word.begin(),word.end());
        int count = 0;
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);

        for(int i=0;i<word.length();i++){
            if(islower(word[i])){
                lastLower[word[i]-'a']=i;
            }
            
        }

        for(int i=0;i<word.length();i++){
            if(isupper(word[i]) && firstUpper[word[i]-'A'] == -1){
                     firstUpper[word[i]-'A'] = i;
            }
            
        }
        for(char ch='a';ch<='z';ch++){
            if(s.count(ch)==1 && s.count(toupper(ch))==1 && lastLower[ch-'a']<firstUpper[ch-'a']){
                count++;
            }
        }
        return count;
    }
};