class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        set<int> s;

        for(int i=0;i<n;i++){
            s.clear();
            for(int j=i;j<n;j++){
                s.insert(nums[j]);
                ans += (s.size()*s.size());
            }
        }

        return ans;
    }
};