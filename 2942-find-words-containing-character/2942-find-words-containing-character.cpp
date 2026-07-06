class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                if(find(words[i].begin(),words[i].end(),x)!=words[i].end()){
                    result.push_back(i);
                    break;

                }
            }
        }
        return result;
        
    }
};