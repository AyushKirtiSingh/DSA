class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool ans = false;

        if((rec1[2]-rec2[0])>0 && (rec1[3]-rec2[1])>0 && (rec2[2]-rec1[0])>0 && (rec2[3]-rec1[1])>0){
            ans = true;
        }
        else{
            ans = false;
        }

        return ans;
    }
};