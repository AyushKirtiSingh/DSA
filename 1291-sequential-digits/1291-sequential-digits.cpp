class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        string num = "";
        int ans = 0;
        vector<int> nums;
        vector<int> result;

        for(int len =2; len<=9;len++){
            for(int i=0;i<=9-len;i++){
                num = s.substr(i,len);
                ans = stoll(num);
                nums.push_back(ans);
            }
        }

        for(int x : nums){
            if(x>=low && x<=high){
                result.push_back(x);
            }
        }
        return result;
        
    }
};