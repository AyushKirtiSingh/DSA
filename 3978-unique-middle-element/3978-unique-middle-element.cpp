class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();

        for(int x : nums){
            m[x]++;
        }

        if(m[nums[n/2]]==1){
            return true;
        }
        else{
            return false;
        }

        
    }
};