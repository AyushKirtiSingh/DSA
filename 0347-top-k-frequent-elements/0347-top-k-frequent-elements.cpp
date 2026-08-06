class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> result;

        for(int x: nums){
            if(m.find(x)==m.end()){   //agar element hoga pehle se toh woh uske freq yani ki second mein ek ka increment kar dega aur nhi hua toh uss value ko insert kar dega map ke andar with freq 1.
                m[x] = 1;
            }
            else{
                m[x]++;
            }
        }

        vector<pair<int,int>> v;   //vector pair ka use kiye h k frequent elements ke liye

        for(auto &it : m){
            v.push_back({it.second,it.first});  //pushing each element first frequency then the lement so that hen sort function is used it should
        }

        sort(v.begin(),v.end(),greater<pair<int,int>>());

        for(int i=0;i<k;i++){
            result.push_back(v[i].second);
        }

        return result;

        
    }
};