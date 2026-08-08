class Solution {
public:

    // Number ko reverse karta hai
    long long rev(long long n) {
        string ans = "";
        string str = to_string(n);

        for(int i = str.length() - 1; i >= 0; i--) {
            ans += str[i];
        }

        return stoll(ans);
    }


    int countNicePairs(vector<int>& nums) {
        const long long MOD = 1000000007;

        long long count = 0;

        // nums[i] ko nums[i] - rev(nums[i]) mein transform karo
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] - rev(nums[i]);
        }

        // Har transformed value ki frequency store karega
        unordered_map<int, int> m;

        for(int x : nums) {

            // Agar x pehli baar aaya hai
            if(m.find(x) == m.end()) {
                m[x] = 1;
            }

            else {
                // Jitni baar x pehle aaya, utne new pairs banenge
                count += m[x];

                // Current x ko bhi frequency mein add karo
                m[x]++;
            }
        }

        // Answer ko MOD ke according return karo
        return count % MOD;
    }
};