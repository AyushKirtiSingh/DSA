// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int st = 1, end = n, ans = -1;

        while(st<=end){
            int mid = st + (end-st)/2;
            if(isBadVersion(mid)==true){
                ans = mid;
                end = mid -1;     //mid milne ke baad bhi aur chote ke liye search karega

            }
            else{
                st = mid + 1;
            }
        }
        return ans;
    }
};