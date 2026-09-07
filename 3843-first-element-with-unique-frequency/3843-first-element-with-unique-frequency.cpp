class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> m;

        for(int x : nums){
            if(m.find(x)==m.end()){
                m[x] = 1;
            }
            else{
                m[x]++;
            }
        }

        unordered_map<int,int> f;

        for(auto it : m){
            if(f.find(it.second)==f.end()){
                f[it.second] = 1;
            }
            else{
                f[it.second]++;
            }
        }

        for(int i=0;i<nums.size();i++){
            if(f[m[nums[i]]]==1){
                return nums[i];
            }
        }

        return -1;
    }
};