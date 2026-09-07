class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> m;
        string ans = "";

        for(char x : s){
            if(m.find(x)==m.end()){
                m[x] = 1;
            }
            else{
                m[x]++;
            }
        }
        unordered_map<int,int> q;

        for(auto it : m){
            if(q.find(it.second)==q.end()){
                q[it.second]=1;
            }
            else{
                q[it.second]++;
            }
        }

        int maxi = 0;
        int freq = 0;

        for(auto it : q){
            if(it.second > maxi || (it.second == maxi && it.first > freq)){
                maxi = it.second;
                freq = it.first;
            }
        }

        set<char> str;

        for(char x : s){
            str.insert(x);
        }

        for(char x : str){
            if(m[x]==freq){
                ans += x;
            }
        }

        return ans;
    }
};