class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minval = INT_MAX;
        int maxval = INT_MIN;
        int leftidx = 0;
        int rightidx = 0;
        int minidx = 0;
        int maxidx = 0;

        // Array se minimum value find kar rahe hain
        for(int i=0;i<nums.size();i++){
            minval = min(minval,nums[i]);
        }

        // Array se maximum value find kar rahe hain
        for(int i=0;i<nums.size();i++){
            maxval = max(maxval,nums[i]);
        }

        // Maximum ki first occurrence ka index
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxval){
                maxidx = i;
                break;
            }
        }

        // Minimum ki first occurrence ka index
        for(int i=0;i<nums.size();i++){
            if(nums[i]==minval){
                minidx = i;
                break;
            }
        }

        // Dono indices mein leftmost aur rightmost nikal rahe hain
        leftidx = min(maxidx,minidx);
        rightidx = max(maxidx,minidx);

        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 0;

        // Dono ends se deletion
        ans1 = (leftidx + 1) + (nums.size()-rightidx);

        // Left se delete karke rightmost element tak
        ans2 = (rightidx + 1);

        // Right se delete karke leftmost element tak
        ans3 = (nums.size()-leftidx);

        // Teeno possible approaches mein minimum deletions
        return min(ans1,min(ans2,ans3));

        
    }
};