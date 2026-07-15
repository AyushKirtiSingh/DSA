class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        set<int> s1;
        set<int> s2;
        set<int> s3;
        int max = INT_MIN;
        int oddsum = 0;
        int evensum = 0;

       oddsum = n * n;
       evensum = n * (n+1);

        for(int i=1;i<=evensum;i++){
            if(evensum%i==0){
                s1.insert(i);
            }
        }

        for(int i=1;i<=oddsum;i++){
            if(oddsum%i==0){
                s2.insert(i);
            }
        }

        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s3,s3.begin()));

     
        for(int x:s3){
            if(x>max){
                max = x;
            }

        }
        return max;           
         
    }
};