class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size()-1;
        int j = nums2.size()-1;

        while(i>=m){
            int temp = nums1[i];
            nums1[i] = nums2[j];
            nums2[j] = temp;
            i--;
            j--;
        }

        sort(nums1.begin(),nums1.end());

        
    }
};