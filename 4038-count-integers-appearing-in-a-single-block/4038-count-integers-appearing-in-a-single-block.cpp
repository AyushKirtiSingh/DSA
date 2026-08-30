class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int> m;

        m[nums[0]] = 1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                m[nums[i]]++;
            }
        }

        for(auto it : m){
            if(it.second==1){
                count++;
            }
        }

        return count;
    }
};