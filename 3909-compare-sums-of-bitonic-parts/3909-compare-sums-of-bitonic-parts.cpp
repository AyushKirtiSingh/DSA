class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long n = nums.size();
        long long idx = 0;
        long long max = nums[0];
        long long sum1 = 0;
        long long sum2 = 0;
        for(long long i=0;i<n;i++){
            if(nums[i]>max){
                idx = i;
                max = nums[i];
            }
        }

        for(long long i = 0;i<=idx;i++){
            sum1 += nums[i];
        }

        for(int i=idx;i<n;i++){
            sum2 += nums[i];
        }

        if(sum1>sum2){
            return 0;
        }
        else if(sum1<sum2){
            return 1;
        }
        return -1;
        

    }
};