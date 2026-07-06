class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        int add = 0;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        
        for(int i=0;i<nums.size();i++){
            string str = to_string(nums[i]);
            for(int i=0;i<str.length();i++){
                char ch = str[i]-'0';
                add += ch;
            }
        }

        int result = sum - add;
        return result;

        
        
    }
};