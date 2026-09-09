class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;

        // 1000 se chhote numbers mein comma nahi hota
        if(n<1000) return 0;

        // 1000 se 999999 tak har number mein 1 comma
        if(n>=1000 && n<pow(10,6)){
            count += (n-1000)+1;
        }

        // 1000000 se 999999999 tak har number mein 2 commas
        // Pehle 1000 se 999999 tak ke 1-comma numbers count karo
        // Phir 1000000 se n tak ke 2-comma numbers count karo
        if(n>=pow(10,6) && n<pow(10,9)){
            count += (pow(10,6)-1000);
            count += ((n-pow(10,6))+1)*2;
        }

        // 1000000000 se 999999999999 tak har number mein 3 commas
        // Pehle 1-comma aur 2-comma ranges ka contribution
        // Phir current range ke har number ke 3 commas
        if(n>=pow(10,9) && n<pow(10,12)){
            count += (pow(10,6)-1000);
            count += (pow(10,9)-pow(10,6))*2;
            count += ((n-pow(10,9))+1)*3;
        }

        // 1000000000000 se 999999999999999 tak har number mein 4 commas
        // Pehle 1, 2 aur 3 comma ranges ka contribution
        // Phir current range ke har number ke 4 commas
        if(n>=pow(10,12) && n<pow(10,15)){
            count += (pow(10,6)-1000);
            count += (pow(10,9)-pow(10,6))*2;
            count += (pow(10,12)-pow(10,9))*3;
            count += ((n-pow(10,12))+1)*4;
        }

        // n = 10^15 par number mein 5 commas hote hain
        // Pehle 1, 2, 3 aur 4 comma ranges ka contribution
        // Phir 10^15 ke liye 5 commas add karo
        if(n==pow(10,15)){
            count += (pow(10,6)-1000);
            count += (pow(10,9)-pow(10,6))*2;
            count += (pow(10,12)-pow(10,9))*3;
            count += (pow(10,15)-pow(10,12))*4;
            count += ((n-n)+1)*5;
        }

        return count;
    }
};