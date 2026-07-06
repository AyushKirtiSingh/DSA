class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector <int> ans(nums.size(),0);
        int idx = 0;
        for(int i=0;i<nums.size();i++){
                if(nums[i]%2==0){
                ans[idx]=nums[i];
                idx+=2;
            }
        }
        idx = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                ans[idx]=nums[i];
                idx+=2;
            }
        }
        return ans;
    
    }
};