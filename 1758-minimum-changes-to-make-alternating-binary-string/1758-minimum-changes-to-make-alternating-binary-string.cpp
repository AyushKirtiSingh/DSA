class Solution {
public:
    int minOperations(string s) {
        int startWith0 = 0;
        int startWith1 = 0;

        for (int i = 0; i < s.length(); i++) {
            // Pattern: 010101...
            if (i % 2 == 0) {
                if (s[i] != '0') startWith0++;
            } else {
                if (s[i] != '1') startWith0++;
            }

            // Pattern: 101010...
            if (i % 2 == 0) {
                if (s[i] != '1') startWith1++;
            } else {
                if (s[i] != '0') startWith1++;
            }
        }

        return min(startWith0, startWith1);
    }
};