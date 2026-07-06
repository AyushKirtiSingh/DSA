class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(),nums.end());

        for(int s3=nums.size()-1;s3>1;s3--){
            for(int s1=0,s2=s3-1;s2>s1;){
                if(nums[s3]<nums[s1]+nums[s2]){
                    count += s2-s1;
                    s2--;
                }
                else{
                    s1++;
                }
            }
        }
        return count;
        
    }
};