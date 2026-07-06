class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int distance;
        int mindistance = INT_MAX;

        for(int i=0;i<nums.size();i++){
            distance = 0;
            if(nums[start]==target){
                return 0;
            }
            else if(nums[i]==target){
                distance = abs(start-i);

                mindistance = min(distance,mindistance);
            }

            
        }
        
        return mindistance;
    }
};