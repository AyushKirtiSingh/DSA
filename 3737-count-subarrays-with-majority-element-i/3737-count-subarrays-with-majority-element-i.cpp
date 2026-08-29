class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int> m;
            int count = 0;
            int count1 = 0;   //count of the target element in every subarray
            for(int j=i;j<nums.size();j++){
                if(nums[j]==target){
                    count1++;
                }

                count++;

                if(count1>count/2){     //condition given in question
                    ans++;
                }
                
            }
            
        }
        return ans;
    }
};