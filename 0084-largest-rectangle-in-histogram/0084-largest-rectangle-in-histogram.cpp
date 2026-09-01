class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxval = 0;
        stack<int> s;
        vector<int> right(n,0);  //right nearest smaller element
        vector<int> left(n,0);   //left nearest smaller element

        //Right smaller nearest element : O(n)
        for(int i=n-1;i>=0;i--){
            while(s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                right[i] = n;
            }
            else{
                right[i] = s.top();
            }
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        //Left smaller nearest element : O(n)
        for(int i=0;i<n;i++){
            while(s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                left[i] = -1;
            }
            else{
                left[i] = s.top();
            }
            s.push(i);
        }

        for(int i=0;i<n;i++){      //TC : O(n)
            int width = right[i] - left[i] - 1;
            int currarea = heights[i] * width;
            maxval = max(maxval,currarea);
        }

        return maxval;
        
        
    }
};