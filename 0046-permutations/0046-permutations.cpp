class Solution {
public:
    void getperms(vector<int>& nums,int idx,vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back({nums});
            return;                     //void mein jab bhi koi function khatam hota h toh woh return back karta h
        }

        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);     //make a choice
            getperms(nums,idx+1,ans);    //explore
            swap(nums[idx],nums[i]);     //undo the choice (backtracking)
        }
    }
    

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        getperms(nums,0,ans);
        return ans;
        
    }
};