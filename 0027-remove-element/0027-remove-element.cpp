class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i =0;
        int j = nums.size()-1;
        unordered_map<int,int> m;
        int ans = 0;

        while(i<=j){
            if(nums[i]==val && nums[j]==val){
                j--;
            }
            else if(nums[i]==val && nums[j]!=val){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            else{
                i++;
            }
        }

        for(int x: nums){
            m[x]++;
        }

        ans = nums.size()-m[val];

        return ans;


        
    }
};