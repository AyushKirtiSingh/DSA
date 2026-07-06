class Solution {
public:
    vector <string> nums;
    vector<string> fizzBuzz(int n) {
        for(int i=1;i<=n;i++){
            
            if(i%3==0 && i%5==0){
                nums.push_back("FizzBuzz");
            }
            else if(i%3==0){
                nums.push_back("Fizz");
            }
            else if(i%5==0){
               nums.push_back("Buzz");
            }
            else{
                string j = to_string(i);
                nums.push_back(j);
            }
        }
        return nums;
        
    }
};