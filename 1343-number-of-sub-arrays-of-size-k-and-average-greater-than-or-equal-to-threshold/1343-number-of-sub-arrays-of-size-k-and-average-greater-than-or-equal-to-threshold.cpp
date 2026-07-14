class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int window = 0;
        int count = 0;

        for(int i=0;i<k;i++){
            window += arr[i];           //window will be of size k
        }
        if((window/k)>=threshold){
                count++;
        }

        //Now sliding the window

        for(int i=k;i<arr.size();i++){
            window += arr[i];            //add new element
            window -= arr[i-k];          //remove an element from starting
            if((window/k)>=threshold){
                count++;
            }
        }

        return count;
        
    }
};