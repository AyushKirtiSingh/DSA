class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg = 0;
        int end = nums.size() - 1;
        int loc = -1;

        int mid = (beg+end)/2;

        while(beg<=end && loc==-1){
            if(nums[mid]==target){
                loc = mid;
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
            else{
                beg = mid + 1;
            }

            mid = (beg+end)/2;
        }

        if(loc==-1){
           return beg;

           
        }
        else{
            return loc;
        }
        
    }
};