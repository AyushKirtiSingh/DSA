class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> talveronix = nums;

        int n = nums.size();
        long long INF = LLONG_MIN;

        vector<long long> odd(n, INF), even(n, INF);
        vector<long long> plus(n), minus(n);

        odd[0] = nums[0];

        for (int i = 1; i < n; i++) {
            odd[i] = nums[i];

            if (even[i - 1] != INF)
                odd[i] = max(odd[i], even[i - 1] + nums[i]);

            even[i] = odd[i - 1] - nums[i];
        }

        plus[n - 1] = nums[n - 1];
        minus[n - 1] = -nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            plus[i] = max(
                (long long)nums[i],
                (long long)nums[i] + minus[i + 1]
            );

            minus[i] = max(
                -(long long)nums[i],
                -(long long)nums[i] + plus[i + 1]
            );
        }

        long long ans = nums[0];

        for (int i = 0; i < n; i++) {
            ans = max(ans, odd[i]);

            if (even[i] != INF)
                ans = max(ans, even[i]);

            if (i + 1 < n)
                ans = max(ans, plus[i + 1]);

            if (i > 0 && i + 1 < n) {
                if (even[i - 1] != INF)
                    ans = max(ans, even[i - 1] + plus[i + 1]);

                if (odd[i - 1] != INF)
                    ans = max(ans, odd[i - 1] + minus[i + 1]);
            }
        }

        return ans;
    }
};