class Solution {
public:
    string sortVowels(string s) {

        // Store all vowels from the original string in a separate vector.
        vector<char> ans;

        for(char x : s) {

            // Check whether the current character is a vowel
            // (considering both lowercase and uppercase vowels).
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||
               x=='A'||x=='E'||x=='I'||x=='O'||x=='U') {

                ans.push_back(x);
            }
        }

        // Sort all collected vowels in ascending order.
        sort(ans.begin(), ans.end());

        // idx keeps track of the next vowel to be placed
        // from the sorted vowel vector.
        int idx = 0;

        // Traverse the original string.
        for(int i = 0; i < s.length(); i++) {

            // If the current character is a consonant,
            // leave it unchanged and move to the next character.
            if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' &&
               s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O' && s[i]!='U') {

                continue;
            }
            else {

                // Replace the current vowel with the next
                // vowel from the sorted vowel vector.
                s[i] = ans[idx];

                // Move to the next sorted vowel.
                idx++;
            }
        }

        // Return the string with its vowels sorted.
        return s;
    }
};