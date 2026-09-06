class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;

        int half = n/2;

        for(int x : nums){
            total += x;
        }

        long long sum = 0;

        for(int i=0;i<half;i++){
            sum += nums[i];
        }

        int result = 0;

        for(int i=0;i<n;i++){
            if(sum>total-sum){
                result++;
            }

            sum -= nums[i];
            sum += nums[(i+half)%n];
        }

        return result;
    }
};