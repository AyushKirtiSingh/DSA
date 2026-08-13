class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        // Last digit se start karenge, kyunki carry right se aata hai
        for(int i = digits.size() - 1; i >= 0; i--){

            // Agar digit 9 nahi hai, simply +1 karo
            if(digits[i] != 9){
                digits[i]++;
                break;
            }

            // Agar digit 9 hai, toh 0 karo aur carry left jayega
            else{
                digits[i] = 0;
            }
        }

        // Agar first digit bhi 0 ho gaya,
        // iska matlab saare digits 9 the
        // Example: 999 -> 000, so beginning mein 1 add karo
        if(digits[0] == 0){
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};