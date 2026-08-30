class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minval = INT_MAX;
        int maxval = INT_MIN;
        int leftidx = 0;
        int rightidx = 0;
        int minidx = 0;
        int maxidx = 0;

        for(int i=0;i<nums.size();i++){
            minval = min(minval,nums[i]);
        }

        for(int i=0;i<nums.size();i++){
            maxval = max(maxval,nums[i]);
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxval){
                maxidx = i;
                break;
            }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]==minval){
                minidx = i;
                break;
            }
        }

        leftidx = min(maxidx,minidx);
        rightidx = max(maxidx,minidx);

        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 0;

        ans1 = (leftidx + 1) + (nums.size()-rightidx);
        ans2 = (rightidx + 1);
        ans3 = (nums.size()-leftidx);

        return min(ans1,min(ans2,ans3));

        
    }
};