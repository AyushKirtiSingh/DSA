class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());   //sorting initially to avoid set use to get unique val

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;  //to avoid duplicate elements side by side

            int j = i+1, k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++, k--;
                    while(j<k && nums[j]==nums[j-1]){   //to avoid duplicate elents for fix i
                        j++;
                    }

                }
            }
        }
        return ans;
        
    }
};