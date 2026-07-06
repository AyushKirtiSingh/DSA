class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int count = 0;
            string str = to_string(nums[i]);
            for(int i=0;i<str.length();i++){
               
                char ch = str[i] - '0';
                count += ch;
            }
            if(count == i){
                return count;
            }
        }
        return -1;
        
        
    }
};