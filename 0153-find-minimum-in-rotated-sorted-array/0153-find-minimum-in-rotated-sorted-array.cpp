class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = n-1;

        if(nums[0]<nums[n-1]){
            return nums[0];    //check karta hai ki rotation huya hai ya nhi
        }

        while(st<end){
            int mid = st + (end-st)/2;
            if(nums[mid]<nums[end]){
                end = mid;   //jab mid chota hoga tab left side mein ya phir mid hi minimum ho skta h issiliye mid = end
            }
            else{
                st = mid + 1;   //jab mid bda hoga matlab min right side mein hoga
            }
        }
        return nums[end];   //because condition tab fail hoti h jab st==end hota h toh return st ya end koi bhi index ki value ko kar skte h kyuki end mein 1 hi element aayega
        
    }
};