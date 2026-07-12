class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m+n-1;
        int i = m-1;
        int j = n-1;

        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[idx] = nums1[i];
                idx--;
                i--;
            }
            else{
                nums1[idx] = nums2[j];
                idx--;
                j--;
            }
        }
        //it handles when i becomes 0 but j>0 as the elements of nums2 is not merged in nums1 but when i>0 in that case there is no need for extra condition as when j=0 but i>0 all the elements are already in its correct position.

        while(j>=0){
            nums1[idx] = nums2[j];
            idx--;
            j--;
        }
        
    }
};