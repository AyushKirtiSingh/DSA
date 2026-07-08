const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;
long long pow10[MAX_N];

int init = [](){
    pow10[0] = 1;
    for(int i = 1;i < MAX_N; i++)
        pow10[i] = (pow10[i-1] * 10LL) % MOD;
    return 0;         
}();

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<pair<int,int>> pref(n+1);         // {digit_sum, non_zero_count}
        vector<long long> num(n + 1, 0);        // prefix concatenated non-zero number % MOD

        for(int i=0;i<n;i++){
            int d = s[i] - '0';

            pref[i+1].first = pref[i].first + d;
            pref[i+1].second = pref[i].second + (d>0);

            // Update concatenated number only when digit is non-zero
            num[i+1] = (d > 0) ? (num[i] * 10LL + d) % MOD : num[i];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for(vector<int> &querie : queries){
            int l = querie[0], r = querie[1] + 1;      // [l,r) half-open

            auto [rsum,rdigits] = pref[r];
            auto [lsum,ldigits] = pref[l];

            int len = rdigits - ldigits;            // length of non-zero digits in range
            long long val = (num[r]-num[l] * pow10[len] % MOD + MOD) % MOD;

            long long digit_sum = rsum - lsum;
            ans.emplace_back((digit_sum * val) % MOD);
        }

        return ans;
         
        
    }
};