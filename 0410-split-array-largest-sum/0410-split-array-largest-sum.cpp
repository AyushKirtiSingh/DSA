class Solution {
public:
    bool isValid(vector<int>& nums, int k, int maxsubarrayallowed){
        int n = nums.size();
        int student = 1;
        int pages = 0;

        for(int i=0;i<n;i++){
            if(nums[i]>maxsubarrayallowed){
                return false;
            }
            if(pages + nums[i] <= maxsubarrayallowed){
                pages += nums[i];
            }
            else{
                student++;
                pages = nums[i];
            }
        }
        if(student<=k){
            return true;
        }
        else{
            return false;
        }
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n){
            return -1;
        }

        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }

        int st = 0, end = sum;
        int ans = -1;

        while(st<=end){
            int mid = st + (end - st)/2;

            if(isValid(nums, k, mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
        
    }
};