class Solution {
public:
    string sortVowels(string s) {
        vector<char> ans;
        vector<char> result;
        int count = 0;
        int temp = s.length();
        unordered_map<int,int> m;
        unordered_map<int,int> first;

        for(int i=0;i<s.length();i++){
            char x = s[i];
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
                if(first.find(x)==first.end()){
                    first[x] = i;
                }
                ans.push_back(x);
            }
            else{
                temp--;
            }
            
        }

        for(int x : ans){
            m[x]++;
        }

        for(auto it : m){
            if(it.second==1){
                count++;
            }
        }

        if(count==temp){
            return s;
        }

        vector<pair<pair<int,int>,char>> v;

        for(auto it : m){
            v.push_back({{it.second,-first[it.first]},it.first});
        }

        sort(v.begin(),v.end(),greater<pair<pair<int,int>,char>>());



        for(int i=0;i<v.size();i++){
            int j=1;
            while(j<=v[i].first.first){
                result.push_back(v[i].second);
                j++;
            }
        }

        int j = 0;

        for(int i=0;i<s.length();i++){
            if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u'){
                continue;
            }
            else{
                s[i] = result[j];
                j++;
                
            }
        }
        return s;
        
    }
};