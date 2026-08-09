// "eat" → sort → "aet"         IMPORTANT EXAMPLE
//                  ↓
//           map["aet"]
//                  ↓
//       ["eat", "tea", "ate"]


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        // key = sorted string, value = original anagram strings
        unordered_map<string, vector<string>> m;

        for(int i = 0; i < strs.size(); i++) {

            // Sorted form ko key banayenge
            string temp = strs[i];
            sort(temp.begin(), temp.end());

            // Original string ko uske anagram group mein daalo
            m[temp].push_back(strs[i]);
        }

        // Har map value ek complete anagram group hai
        for(auto it : m) {
            ans.push_back(it.second);
        }

        return ans;
    }
};