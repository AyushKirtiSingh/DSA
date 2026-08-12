class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int finalsum = 0;
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int j = i+1, k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum<target){
                    j++;
                    int result = abs(sum-target);
                    if(result<ans){
                        finalsum = sum;
                    }
                    ans = min(ans,result);
                    
                }
                else if(sum>target){
                    k--;
                    int result = abs(sum-target);
                    if(result<ans){
                        finalsum = sum;
                    }
                    ans = min(ans,result);
                }
                else if(sum==target){
                    return sum;
                }
                
                
                
            } 
        }
        return finalsum;
        
        
    }
};