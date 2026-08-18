class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        vector<int> ans;

        for(int x : nums){
            if(m.find(x)==m.end()){
                m[x] = 1;
            }
            else{
                m[x]++;
            }
        }

        for(auto it : m){
            if(it.second>n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};