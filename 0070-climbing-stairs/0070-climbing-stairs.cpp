class Solution {
public:
    
    int ways(vector<int> &d , int n){
        
        // Base case: 1 step ke liye sirf 1 way
        if(n==1){
            return 1;
        }

        // Base case: 2 steps ke liye 2 ways
        if(n==2){
            return 2;
        }

        int ans = 0;

        // Agar answer pehle calculate ho chuka hai, directly return karo
        if(d[n]!=0){
            return d[n];
        }

        // Current problem ko do smaller problems mein break kar rahe hain
        ans = ways(d,n-1) + ways(d,n-2);

        // Calculated answer ko future use ke liye store karo
        d[n] = ans;

        return ans;
        
    }

    int climbStairs(int n) {

        // n+1 size taki index n tak access kar sakein
        vector<int> d(n+1);

        // Recursion + memoization se answer calculate
        int ans = ways(d,n);

        return ans;
            
    }
        
    
};