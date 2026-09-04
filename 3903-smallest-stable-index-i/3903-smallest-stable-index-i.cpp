class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxval = 0;
        int index = -1;
        for(int i=0;i<nums.size();i++){
            
            maxval = max(maxval,nums[i]);
            int minval = INT_MAX;
            int j = nums.size()-1;
            while(j>=i){
                minval = min(minval,nums[j]);
                j--;
            }
            long long stable = maxval - minval;
            if(stable<=k){
                index = i;
                break;
            }
            
        }
        return index;
    }
};