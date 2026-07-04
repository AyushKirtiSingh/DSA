class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<pair<int,int>> v;
        
        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        
        mergeSort(v, 0, n - 1, result);
        return result;
    }
    
    void mergeSort(vector<pair<int,int>>& v, int left, int right, vector<int>& result) {
        if(left >= right) return;
        
        int mid = (left + right) / 2;
        mergeSort(v, left, mid, result);
        mergeSort(v, mid + 1, right, result);
        merge(v, left, mid, right, result);
    }
    
    void merge(vector<pair<int,int>>& v, int left, int mid, int right, vector<int>& result) {
        vector<pair<int,int>> temp;
        int i = left, j = mid + 1;
        int rightCount = 0;
        
        while(i <= mid && j <= right) {
            if(v[i].first <= v[j].first) {
                result[v[i].second] += rightCount;
                temp.push_back(v[i++]);
            } else {
                rightCount++;
                temp.push_back(v[j++]);
            }
        }
        
        while(i <= mid) {
            result[v[i].second] += rightCount;
            temp.push_back(v[i++]);
        }
        
        while(j <= right) {
            temp.push_back(v[j++]);
        }
        
        for(int k = left; k <= right; k++) {
            v[k] = temp[k - left];
        }
    }
};