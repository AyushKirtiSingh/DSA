class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> left(nums.size(),0);
        vector<int> right(nums.size(),0);

        left[0] = nums[0];
        right[nums.size()-1] = nums[nums.size()-1];

        for(int i=1;i<nums.size();i++){       //calculating prefix sum
            left[i] = left[i-1] + nums[i];
        }

        for(int i=nums.size()-2;i>=0;i--){    //calculating suffix sum
            right[i] = right[i+1] + nums[i];
        }

        for(int i=0;i<nums.size();i++){      //comparing them whether same or not
            if(left[i]==right[i]){
                return i;
            }
        }
        return -1;

        
    }
};