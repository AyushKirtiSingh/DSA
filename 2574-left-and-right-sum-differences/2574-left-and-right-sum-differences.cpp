class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftsum(nums.size(),0);      //prefix vector
        vector<int> rightsum(nums.size(),0);     //suffix vector
        vector<int> ans(nums.size(),0);          //answer vector

        leftsum[0] = nums[0];
        rightsum[nums.size()-1] = nums[nums.size()-1];

        for(int i=1;i<nums.size();i++){          //prefix
            leftsum[i] = leftsum[i-1] + nums[i];
        }

        for(int i = nums.size()-2;i>=0;i--){      //suffix
            rightsum[i] = rightsum[i+1] + nums[i];
        }
        
        for(int i =0;i<nums.size();i++){      //ans = prefix - suffix
            ans[i] = abs(leftsum[i]-rightsum[i]);
        }

        return ans;
    }
};