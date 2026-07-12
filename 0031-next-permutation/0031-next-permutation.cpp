class Solution {
public:
    void reverse(vector<int>& nums, int i){   //TC: O(n)  SC: O(1)
        int start = i;
        int end = nums.size()-1;
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }    
    
    void nextPermutation(vector<int>& nums) {
       int piv = -1;                       //finding pivot
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


       for(int i=n-1;i>=0;i--){            //next larger element
            if(nums[i]>nums[piv]){
                swap(nums[i],nums[piv]);
                break;
            }
       }
       
       reverse(nums,piv+1);         //reversing form pivot+1 to n-1
        
       //reverse(A.begin()+pivot+1,A.end());
       
    }
};