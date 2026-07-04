class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxindex = 0;
        int m = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > m) {
                m = nums[i];
                maxindex = i;
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(i == maxindex) continue;
            if(m < 2 * nums[i]) {
                return -1;
            }
        }

        return maxindex;
    }
};