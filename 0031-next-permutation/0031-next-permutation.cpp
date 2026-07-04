class Solution {
public:
    void reverse(vector<int>& nums, int i){
        int start = i;
        int end = nums.size()-1;
        while(start<end){
            swap(nums,start,end);
            start++;
            end--;
        }
    }    

    void swap(vector<int>& nums,int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void nextPermutation(vector<int>& nums) {
       int i = nums.size() - 2;
       while(i>=0 && nums[i]>=nums[i+1]){
        i--;
       }
       if(i>=0){
        int j = nums.size() - 1;
        while(j>=0 && nums[j]<=nums[i]){
            j--;
        }
        swap(nums,i,j);
       }
       
       reverse(nums,i+1);

    }
};