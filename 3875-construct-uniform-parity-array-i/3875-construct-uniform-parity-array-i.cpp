class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;

        // This will always return true due to parity of array

        // And the parity rules are:

            // odd − even = odd
            // even − odd = odd
            // odd − odd = even
            // even − even = even

        //  There will be 3 cases :-

        // CASE 1 : All elements are odd
        // In this just copy all the elements in nums2 and it will be fully odd

        // CASE 2 : All elements are even
        // In this just copy all the elements in nums2 and it will be fully even

        // CASE 3 : All elements are mix of odd and even

        // In this we can make it either all even elements or all odd elements. By using 
        // the parity rules
    }
};