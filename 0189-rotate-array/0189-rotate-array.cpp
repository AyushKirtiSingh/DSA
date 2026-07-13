class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> result;
        int r = k%nums.size();


        for(int i=nums.size()-r;i<nums.size();i++){
            result.push_back(nums[i]);

        }
        
        for(int i=0;i<nums.size()-r;i++){
            result.push_back(nums[i]);
        }

        int i = 0;
        int j = 0;

        while(i<nums.size()){
            swap(nums[i],result[j]);
            i++;
            j++;
        }
        
    }
};