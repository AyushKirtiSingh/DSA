class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        long long x = 0;
        long long y = 0;
        long long count = 0;

        for(int i=0;i<nums.size();i++){
            x=0,y=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0){
                    x++;
                }
                else{
                    y++;
                }
                if(y>0 && (x*b*1LL) <= (a*y*1LL)){
                    count++;
                    
                }

            }
        }
        return count;
        
    }
};