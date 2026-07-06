class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
     set<int>s1(nums[0].begin(),nums[0].end());
     for(int i=0;i<nums.size();i++){
     set<int>s2(nums[i].begin(),nums[i].end());
     set<int>r;
     set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(r,r.begin()));
     s1=r;
     }
     vector<int>v(s1.begin(),s1.end());
     return v;
    }
};