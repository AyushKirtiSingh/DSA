class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Result array banaya, initially 0 se fill kiya
        vector<int> result(nums.size(), 0);

        // Positive numbers ke liye even index, negative ke liye odd index
        int i = 0, j = 1;

        for(int k = 0; k < nums.size(); k++) {

            if(nums[k] > 0) {
                // Positive number ko even position par rakho
                result[i] = nums[k];
                i += 2;
            }
            else {
                // Negative number ko odd position par rakho
                result[j] = nums[k];
                j += 2;
            }
        }

        return result;
    }
};