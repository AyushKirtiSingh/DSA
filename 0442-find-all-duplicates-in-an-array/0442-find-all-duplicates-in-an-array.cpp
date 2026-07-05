class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> result;
        int index;
        //sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
                index = abs(nums[i]) - 1;
                if(nums[index]<0){
                   result.push_back(index + 1);
                }
                else{
                    nums[index] *= -1;
                }
        }
        // for(int i=0;i<nums.size() - 1;i++){
        //     if(nums[i]==0){
        //         result.push_back(i+1);
        //     }
        // }
        return result;
        
    }
};