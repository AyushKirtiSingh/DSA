class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size()-1;

        while(left<right){
            int w = right - left;
            int l = min(height[left],height[right]);
            int area = w * l;
            ans = max(ans,area);

            if(height[right]<height[left]){
                right--;
            }
            else{
                left++;
            }
        }
        return ans;
        
    }
};