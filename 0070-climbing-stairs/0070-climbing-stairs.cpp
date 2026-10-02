class Solution {
public:
    
    int ways(vector<int> &d , int n){
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }

        int ans = 0;

        if(d[n]!=0){
            return d[n];
        }

        ans = ways(d,n-1) + ways(d,n-2);

        d[n] = ans;

        return ans;
        
    }

    int climbStairs(int n) {
        vector<int> d(n+1);
        int ans = ways(d,n);

        return ans;
            
    }
        
    
};