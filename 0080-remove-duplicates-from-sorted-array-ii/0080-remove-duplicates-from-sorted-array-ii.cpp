// Intuition:
// Array sorted hai aur har element maximum 2 baar allowed hai.
// Current element ko nums[k-2] se compare karenge.
// Same -> third duplicate hoga, skip
// Different -> valid hai, nums[k] par store karo

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1){     //agar ek hi element hoga toh count bhi 1 hi hoga
            return 1;
        }
        int k = 2;   //next valid element ka index track karega
        for(int i=2;i<nums.size();i++){   //bas count 2 ho skta h toh i=2 se shuru karenge aur same element teesri baar ayega toh skip kar denge
            if(nums[i]==nums[k-2]){
                continue;               
            }
            else{
                nums[k] = nums[i];    
                k++;      //agar next eelement valid hoga yaani ki different toh use k par store karke k ko increment karenge
            }
            
        }
        return k;    //k will give the total no of unique elements at most twice appearence
        
    }
};