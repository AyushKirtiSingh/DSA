class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;

        while(j<nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }
            else{
                i++;
                nums[i] = nums[j];
            }
        }

        set<int> s;

        for(int x:nums){
            s.insert(x);
        }

        return s.size();
        
        
    }
};