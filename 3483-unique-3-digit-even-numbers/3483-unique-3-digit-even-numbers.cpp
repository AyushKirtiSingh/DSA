class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_map<int,int> m;

        for(int i=0;i<n;i++){
            int number = digits[i];
            if(number == 0){
                continue;
            }
            for(int j=0;j<n;j++){
                int temp1 = number;
                temp1 = temp1*10 + digits[j];
                for(int k=0;k<n;k++){
                    if(i==j || j==k || i==k){
                        continue;
                    }
                    int temp2 = temp1;
                    temp2 = temp2*10 + digits[k];
                    if(temp2%2==0){
                        if(m.find(temp2)==m.end()){
                            m[temp2] = 1;
                        }
                        else{
                            m[temp2]++;
                        }
                    }

                }

            }

        }

        int count = 0;

        for(auto it : m){
            count++;
            
        }

        return count;
    }
};