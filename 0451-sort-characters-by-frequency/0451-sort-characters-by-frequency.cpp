// String
//   ↓
// Map → character ki frequency
//   ↓                                     CORE LOGIC FOR REVISION
// Vector<pair<int,char>>
//   ↓
// Frequency ke basis par descending sort
//   ↓
// Har character ko frequency times add
//   ↓
// Answer

class Solution {
public:
    string frequencySort(string s) {

        // Har character ki frequency store karenge
        unordered_map<char, int> m;

        for(char x : s){
            if(m.find(x) == m.end()){
                m[x] = 1;
            }
            else{
                m[x]++;
            }
        }

        // Pair: {frequency, character}
        vector<pair<int, char>> v;

        // Map ko vector mein convert kar rahe hain
        for(auto &it : m){
            v.push_back({it.second, it.first});
        }

        // Frequency ke descending order mein sort
        sort(v.begin(), v.end(), greater<pair<int, char>>());

        string ans = "";

        // Har character ko uski frequency jitni baar add karo
        for(int i = 0; i < v.size(); i++){
            while(v[i].first != 0){
                ans += v[i].second;
                v[i].first--;
            }
        }

        return ans;
    }
};