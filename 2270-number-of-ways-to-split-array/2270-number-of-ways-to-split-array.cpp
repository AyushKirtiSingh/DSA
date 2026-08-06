class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        vector<long long> left(n,0);
        vector<long long> right(n,0);

        left[0] = nums[0];
        right[n-1] = nums[n-1];

        for(int i=1;i<n;i++){                //prefix sum
            left[i] = left[i-1] + nums[i];
        }

        for(int i=n-2;i>=0;i--){
            right[i] = right[i+1] + nums[i];  //suffix sum
        }

        for(int i=0;i<n-1;i++){
            if(left[i]>=right[i+1]){  //we take right[i+1] because nums[i] will come in both if we take right[i] and to prevent that it is necessary
                count++;
            }
        }
        return count;
        
    }
};