class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        long long sum2 = 0;

        int half = n/2;

        long long sum1 = 0;

        for(int i=0;i<half;i++){
            sum1 += nums[i];
        }

        for(int i=half;i<n;i++){
            sum2 += nums[i];
        }

        int result = 0;

        for(int i=0;i<n;i++){
            if(sum1>sum2){
                result++;
            }

            sum1 -= nums[i];
            sum1 += nums[(i+half)%n];

            sum2 -= nums[(half+i) % n];
            sum2 += nums[i];
        }

        return result;
    }
};