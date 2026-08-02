class Solution {
public:
    set<vector<int>> s;  //using to get unique values only and remove duplicate values
    void combsum(vector<int>& arr, int i, vector<int> &comb, vector<vector<int>> &ans, int target){

        if(i==arr.size() || target<0){   //base case when target becomes zero or negative
            return;
        }
        if(target==0){
            if(s.find(comb)==s.end()){
                ans.push_back(comb);      //step of removing duplicates
                s.insert(comb);
            }
            return;
            
        }

        //inclusion of element
        comb.push_back(arr[i]);
        combsum(arr,i+1,comb,ans,target-arr[i]);   //single time include element
        combsum(arr,i,comb,ans,target-arr[i]);   //multiple time include element
        comb.pop_back();   //backtracking
        combsum(arr,i+1,comb,ans,target);    //not including the element
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> comb;

        combsum(arr,0,comb,ans,target);     //Time Complexity: Exponential
                                           // Space Complexity: O(output space + recursion stack)

        return ans;
        
    }
};