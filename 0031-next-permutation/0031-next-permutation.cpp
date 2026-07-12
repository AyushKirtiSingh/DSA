class Solution {
public:
    void reverse(vector<int>& nums, int i){
        int start = i;
        int end = nums.size()-1;
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }    

    void myswap(vector<int>& nums,int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void nextPermutation(vector<int>& nums) {
       int piv = -1;
       int n = nums.size();

       for(int i=n-2;i>=0;i--){
           if(nums[i]<nums[i+1]){
              piv = i;
              break;
           }
       }

       if(piv==-1){
           reverse(nums,0);
           return;
       }


       for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[piv]){
                myswap(nums,i,piv);
                break;
            }
       }
       
       reverse(nums,piv+1);
        
       
    }
};