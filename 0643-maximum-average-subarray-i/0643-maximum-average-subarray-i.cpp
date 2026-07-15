class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double windowsum = 0;
        double maxval = INT_MIN;
        double avg = 0;

        for(int i=0;i<k;i++){
            windowsum += nums[i];
        }
        avg = windowsum/k;
        maxval = max(avg,maxval);

        for(int i=k;i<nums.size();i++){
            windowsum += nums[i];
            windowsum -= nums[i-k];
            avg = windowsum/k;
            maxval = max(avg,maxval);
        }

        return maxval;
        
    }
};