class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        // Stores the actual 3-number sum which is closest to the target.
        int finalsum = 0;

        // Sorting allows us to use the two-pointer technique.
        sort(nums.begin(), nums.end());

        // Stores the minimum absolute difference found so far.
        // Initially set to INT_MAX so that the first valid sum will definitely be better.
        int ans = INT_MAX;

        // Fix the first element of the triplet.
        for(int i = 0; i < n; i++){

            // Skip duplicate values for the fixed element.
            // This is not strictly necessary for correctness here,
            // but avoids processing the same starting value repeatedly.
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            // Two pointers:
            // j starts just after i.
            // k starts at the end of the array.
            int j = i + 1, k = n - 1;

            while(j < k){

                // Current sum of the three selected elements.
                int sum = nums[i] + nums[j] + nums[k];

                // If current sum is smaller than target,
                // we need a larger sum, so move j to the right.
                if(sum < target){
                    j++;

                    // Calculate how far the current sum is from the target.
                    int result = abs(sum - target);

                    // If this is the closest sum found so far,
                    // store the actual sum.
                    if(result < ans){
                        finalsum = sum;
                    }

                    // Update the minimum difference.
                    ans = min(ans, result);
                }

                // If current sum is greater than target,
                // we need a smaller sum, so move k to the left.
                else if(sum > target){
                    k--;

                    // Calculate the difference from the target.
                    int result = abs(sum - target);

                    // If this sum is closer than our previous best,
                    // store the actual sum.
                    if(result < ans){
                        finalsum = sum;
                    }

                    // Update the minimum difference.
                    ans = min(ans, result);
                }

                // If sum exactly equals target,
                // this is the best possible answer.
                else if(sum == target){
                    return sum;
                }
            }
        }

        // Return the 3-number sum closest to the target.
        return finalsum;
    }
};