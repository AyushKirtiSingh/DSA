class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> m;
        int count = 0;
        for(int x : nums){
            m[x]++;
            if(x%2==0)count++;
        }
        if(count==0)return -1;

        vector<pair<int,int>> v;

        for(auto &it : m){
            v.push_back({it.first,it.second});
        }

        int maxval = INT_MIN;
        int minval = INT_MAX;
        
        for(int i=0;i<v.size();i++){
            if(v[i].first % 2 == 0){
                if(v[i].second>maxval){
                    maxval = v[i].second;
                    minval = v[i].first;
                }
                else if(v[i].second==maxval){
                    minval = min(v[i].first,minval);
                }
            }
            
        }
        return minval;
    }
};