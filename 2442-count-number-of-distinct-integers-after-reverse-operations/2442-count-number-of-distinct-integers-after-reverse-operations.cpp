class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s1;

        for(int val : nums){
            s1.insert(val);
        }

        for(int i=0;i<nums.size();i++){
            int reversednum = 0;
            while(nums[i]!=0){
                int lastdigit = nums[i]%10;
                reversednum = reversednum * 10 + lastdigit;
                nums[i] = nums[i]/10;
            }
            s1.insert(reversednum);
        }

        return s1.size();

    }
};