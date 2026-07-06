class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result1;
        vector<int> result2;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<vector<int>> result;
        for(int i=0;i<nums1.size();i++){

            if(i>0 && nums1[i]==nums1[i-1]){
                continue;
            }
            
            else if(find(nums2.begin(),nums2.end(),nums1[i])==nums2.end()){
                result1.push_back(nums1[i]);
            }
            
        }
        for(int i=0;i<nums2.size();i++){

            if(i>0 && nums2[i]==nums2[i-1]){
                continue;
            }
            
            if(find(nums1.begin(),nums1.end(),nums2[i])==nums1.end()){
                result2.push_back(nums2[i]);
            }
            
        }
        result.push_back(result1);
        result.push_back(result2);
        return result;
        
    }
};