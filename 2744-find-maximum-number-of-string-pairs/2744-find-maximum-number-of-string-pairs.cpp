class Solution {
public:
    string rev(string s){
        string ans;
        for(int i=s.length()-1;i>=0;i--){
            ans += s[i];
        }
        return ans;

    }

    int maximumNumberOfStringPairs(vector<string>& words) {
        int count = 0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(i!=j && words[i]==rev(words[j])){
                    count++;
                }
            }
        }
        return count/2;
        
    }
};