class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int> m;

        // First element always starts the first block
        m[nums[0]] = 1;

        for(int i=1;i<nums.size();i++){
            // A new block starts whenever the current value differs from the previous one
            if(nums[i]!=nums[i-1]){
                m[nums[i]]++;
            }
        }

        // An integer is special if all its occurrences form exactly one block
        for(auto it : m){
            if(it.second==1){
                count++;
            }
        }

        return count;
    }
};