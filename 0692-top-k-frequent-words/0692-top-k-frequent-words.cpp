class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++){
            if(m.find(words[i])==m.end()){
                m[words[i]] = 1;
            }
            else{
                m[words[i]]++;
            }

        }

        vector<pair<int,string>> v;

        for(auto it : m){
            v.push_back({it.second,it.first});
        }

        sort(v.begin(),v.end(),[](pair<int,string> a,pair<int,string> b){
        if(a.first != b.first){
            return a.first > b.first;
        }
        return a.second < b.second;
    });

        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }

        return ans;

        
    }
};