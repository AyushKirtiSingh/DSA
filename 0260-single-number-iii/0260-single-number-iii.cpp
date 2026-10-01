class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int>ans;

        for(int x : nums){
            m[x]++;
        }

        for(auto it:m){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }

        return ans;
        
    }
};