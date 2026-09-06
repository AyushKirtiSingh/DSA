class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.length();
        int ans = 0;

        // Har possible rotation check karo
        for(int i=0;i<n;i++){
            // i se rotate karke new string banao
            string t = s.substr(i) + s.substr(0,i);

            int score = 0;

            // Adjacent characters compare karo
            for(int j=0;j<n-1;j++){
                // Same characters mile to score badhao
                if(t[j]==t[j+1]){
                    score++;
                }
            }

            // Score k ke equal hai to answer badhao
            if(score==k){
                ans++;
            }
        }

        // Valid rotations ki count return karo
        return ans;
        
    }
};