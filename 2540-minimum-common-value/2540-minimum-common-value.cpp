class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;
        set<int> s3;

        for(int v: nums1){
            s1.insert(v);
        }

        for(int v: nums2){
            s2.insert(v);
        }

        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s3,s3.begin()));

        for(int v: s3){
            return v;
            break;
        }
        return -1;
        
    }
};