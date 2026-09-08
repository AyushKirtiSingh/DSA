class Solution {
public:
    int countCommas(int n) {
        int count = 0;
        if(n<1000){
            return count;
        }

        for(int i=1000;i<=n;i++){
            string str = to_string(i);
            if(str.length()>=3){
                count += (str.length()-1)/3;  
                // -1 kiye hai kyunki commas digits ke beech mein lagte h digits ke baad nhi jaise 999 mein nhi lgega kyunki wo 3 digits h comma ke baad 3 digits hone chahiye matlab total length 3 ke multiple se ek zyada chahiye uss hisaab se count calculate hoga.
            }
        }

        return count;
    }
};