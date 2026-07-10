class Solution {
public:
    bool isValid(vector<int>& weights, int days, int maxweightallowed){
        int n = weights.size();
        int weight = 0;
        int students = 1;

        for(int i=0;i<n;i++){
            if(weights[i]>maxweightallowed){
                return false;
            }

            if(weight + weights[i] <= maxweightallowed){
                weight += weights[i];
            }
            else{
                students++;
                weight = weights[i];
            }
        }
        if(students>days){
            return false;
        }
        else{
            return true;
        }
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int sum = 0;
        for(int i=0;i<n;i++){
            sum += weights[i];
        }

        int st = *max_element(weights.begin(),weights.end()), end = sum;
        int ans = -1;

        while(st<=end){
            int mid = st + (end - st)/2;

            if(isValid(weights,days,mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
        
    }
};