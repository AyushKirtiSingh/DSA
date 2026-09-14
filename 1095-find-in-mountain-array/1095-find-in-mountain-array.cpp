/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = 0;
        int st = 0;
        int end = n-2;
        int ans = INT_MAX;

        while(st<=end){
            int mid = st + (end-st)/2;
            if(mid!=0){
                int l = mountainArr.get(mid-1);
            int r = mountainArr.get(mid+1);
            int m = mountainArr.get(mid);
            if(l<m && m>r){
                peak = mid;
                break;
            }
            else if(l<m){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }

            }
            else{
                st++;
            }
            
        }

        st = 0, end = peak;

        while(st<=end && ans==INT_MAX){
            int mid = st + (end-st)/2;
            int m = mountainArr.get(mid);

            if(m==target){
                ans = min(ans,mid);
            }
            else if(m<target){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        st = peak, end=n-1;

        while(st<=end && ans==INT_MAX){
            int mid = st + (end-st)/2;
            int m = mountainArr.get(mid);

            if(m==target){
                ans = min(ans,mid);
            }
            else if(m>target){
                st = mid + 1;
            }
            else{
                end = mid -1;
            }
        }

        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans;
        }

        
    }
};