class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int f = flowerbed.size();
        int count = 0;
        if(n==0)return true; // Agar flower nahi chahiye toh true

        for(int i=0;i<f;i++){
            // Check karo current aur adjacent plots khaali hain
            if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==f-1 || flowerbed[i+1]==0)){
                count++;
                if(count == n){
                    return true; // Required flowers plant ho gaye
                }
                flowerbed[i] = 1; // Plot ko occupied mark karo
            }
        }
        return false; // Enough khaali plots nahi mile
    }
};