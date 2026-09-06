class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n,0);    //TC : O(N)  && SC : O(N)
        vector<int> suffix(n,INT_MAX);    // Precomputation of prefix maxval and suffix minval for each i and storing them in a new vector prefix and suffix is main concept to reduce Time.
        int index = -1;

        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i=1;i<n;i++){
            prefix[i] = max(nums[i],prefix[i-1]);    //PREFIX : MAX(NUMS[I],PREFIX[I-1])
        }

        for(int i=n-2;i>=0;i--){
            suffix[i] = min(nums[i],suffix[i+1]);    //SUFFIX : MIN(NUMS[I],SUFFIX[I+1])
        }

        for(int i=0;i<n;i++){
            nums[i] = prefix[i] - suffix[i];
            if(nums[i]<=k){
                index = i;
                break;
            }
        
        }

        return index;
    }
};