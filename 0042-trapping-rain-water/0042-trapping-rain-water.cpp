class Solution {
public:
    int trap(vector<int>& height) {   //T.C = O(n) && S.C = O(n)
        int n = height.size();
        int ans = 0;
        vector<int> lmax(n,0);
        vector<int> rmax(n,0);     //Prefix array approach

        lmax[0] = height[0];
        rmax[n-1] = height[n-1];

        for(int i=1;i<n;i++){
            lmax[i] = max(lmax[i-1],height[i]);
        }

        for(int i=n-2;i>=0;i--){
            rmax[i] = max(rmax[i+1],height[i]);
        }

        for(int i=0;i<n;i++){
            ans += max(0,min(rmax[i],lmax[i]) - height[i]);
        }

        return ans;
    }
};