class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        
        vector<int> result;
        for(int i=0;i<=100;i++){
            int count = 0;
            if(find(nums1.begin(),nums1.end(),i)!=nums1.end()){
                count++;
            }
            if(find(nums2.begin(),nums2.end(),i)!=nums2.end()){
                count++;
            }
            if(find(nums3.begin(),nums3.end(),i)!=nums3.end()){
                count++;
            }
            if(count>=2){
                result.push_back(i);
            }
        }
        return result;
        
    }
};