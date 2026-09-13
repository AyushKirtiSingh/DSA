class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_map<int,int> m;

        // First digit choose kar rahe hain
        for(int i=0;i<n;i++){
            int number = digits[i];

            // 3-digit number ka first digit 0 nahi ho sakta
            if(number == 0){
                continue;
            }

            // Second digit choose kar rahe hain
            for(int j=0;j<n;j++){
                int temp1 = number;
                temp1 = temp1*10 + digits[j];

                // Third digit choose kar rahe hain
                for(int k=0;k<n;k++){

                    // Same index ko dobara use nahi karna
                    if(i==j || j==k || i==k){
                        continue;
                    }

                    // Third digit add karke 3-digit number banaya
                    int temp2 = temp1;
                    temp2 = temp2*10 + digits[k];

                    // Last digit even hona chahiye
                    if(temp2%2==0){

                        // Number pehli baar mila toh frequency 1
                        if(m.find(temp2)==m.end()){
                            m[temp2] = 1;
                        }

                        // Number pehle mil chuka hai, frequency increase
                        else{
                            m[temp2]++;
                        }
                    }
                }
            }
        }

        int count = 0;

        // Map ki har key ek distinct valid number represent karti hai
        for(auto it : m){
            count++;
        }

        return count;
    }
};