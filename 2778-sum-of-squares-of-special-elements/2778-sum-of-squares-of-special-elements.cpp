class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            int ans = 0;
            if(n % (i+1)==0){
                ans = nums[i]*nums[i];
                sum += ans;
            }
        }
        return sum;
        
    }
};