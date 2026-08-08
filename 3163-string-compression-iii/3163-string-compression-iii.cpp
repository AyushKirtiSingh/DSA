class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int n = word.length();

        for(int i = 0; i < n; i++) {

            char ch = word[i];   // Current character
            int count = 0;

            // Count consecutive same characters
            while(i < n && word[i] == ch) {
                count++;
                i++;
            }

            // If only one character is present
            if(count == 1) {
                ans += '1';
                ans += ch;
            }

            // If count is greater than 9, take 9 at a time
            else if(count > 9) {
                ans += '9';
                ans += ch;

                // Move back so remaining characters can be processed
                i = i - (count - 9);
            }

            // If count is between 2 and 9
            else {
                string str = to_string(count);

                // Add count digits to answer
                for(char dig : str) {
                    ans += dig;
                }

                ans += ch;
            }

            // Adjust because for-loop will increment i again
            i--;
        }

        return ans;
    }
};