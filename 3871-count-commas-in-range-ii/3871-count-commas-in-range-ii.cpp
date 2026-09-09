class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        
        if(n<1000) return 0;

        if(n>=1000 && n<pow(10,6)){
            count += (n - 1000) + 1;
        }

        if(n>=pow(10,6) && n<pow(10,9)){
            count += (pow(10,6) - 1000);
            count += ((n-pow(10,6)) + 1) * 2;
        }

        if(n>=pow(10,9) && n<pow(10,12)){
            count += (pow(10,6) - 1000);
            count += ((pow(10,9)-pow(10,6))) * 2;
            count += ((n-pow(10,9)) + 1) * 3;
        }

        if(n>=pow(10,12) && n<pow(10,15)){
            count += (pow(10,6) - 1000);
            count += ((pow(10,9)-pow(10,6))) * 2;
            count += ((pow(10,12)-pow(10,9))) * 3;
            count += ((n-pow(10,12)) + 1) * 4;
        }

        if(n==pow(10,15)){
            count += (pow(10,6) - 1000);
            count += ((pow(10,9)-pow(10,6))) * 2;
            count += ((pow(10,12)-pow(10,9))) * 3;
            count += ((pow(10,15)-pow(10,12))) * 4;
            count += ((n-n)+1) * 5;
        }
        return count;
    }
};