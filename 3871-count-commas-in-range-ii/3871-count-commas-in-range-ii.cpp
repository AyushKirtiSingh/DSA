class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;

        // 1000 se chhote numbers mein koi comma nahi hota
        if(n<1000) return 0;

        // 1000 se n tak har number mein pehla comma hota hai
        if(n>=1000){
            count += (n-1000) + 1;
        }

        // 10^6 se n tak har number mein doosra comma hota hai
        if(n>=pow(10,6)){
            count += (n-pow(10,6)+1);
        }

        // 10^9 se n tak har number mein teesra comma hota hai
        if(n>=pow(10,9)){
            count += (n-pow(10,9)+1);
        }

        // 10^12 se n tak har number mein chautha comma hota hai
        if(n>=pow(10,12)){
            count += (n-pow(10,12)+1);
        }

        // Constraint n <= 10^15 hai, isliye 10^15 par paanchva comma hota hai
        if(n==pow(10,15)){
            count += (n-pow(10,15)+1);
        }

        return count;
        
    }
};