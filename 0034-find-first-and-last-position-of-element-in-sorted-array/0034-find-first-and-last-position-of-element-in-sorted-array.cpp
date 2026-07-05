class Solution {
public:
    int firstoccurenceindex(vector<int>& nums, int target) {
        int beg = 0;
        int end = nums.size()-1;
        int firstindex = -1;
        

        int mid = (beg+end)/2;

        while(beg<=end){
            if(nums[mid]==target){
                firstindex = mid;
                end = mid - 1;
            }
            else if(nums[mid]<target){
                beg = mid + 1;
            }
            else{
                end = mid - 1;
            }

            mid = (beg+end)/2;
        }
        return firstindex;
        
    }

int lastoccurenceindex(vector<int>& nums, int target) {
        int beg = 0;
        int end = nums.size()-1;
        int lastindex = -1;
        

        int mid = (beg+end)/2;

        while(beg<=end){
            if(nums[mid]==target){
                lastindex = mid;
                beg = mid + 1;
            }
            else if(nums[mid]<target){
                beg = mid + 1;
            }
            else{
                end = mid - 1;
            }

            mid = (beg+end)/2;
        }
        return lastindex;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans(2);

    ans[0] = firstoccurenceindex(nums,target);
    ans[1] = lastoccurenceindex(nums,target);

    return ans;
    

    }
};

        

       