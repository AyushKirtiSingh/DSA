class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> ans(indices.size());
        for(int i=0;i<indices.size();i++){
            ans[indices[i]] = s[i];
        }
        string str = "";
        for(int i=0;i<ans.size();i++){
            str += ans[i];
        }

        return str;
        
    }
};