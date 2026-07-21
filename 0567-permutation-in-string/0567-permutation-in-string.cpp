class Solution {
public:
    bool isfreqsame(int freq1[],int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {      //creating freq array and storing each character freq in s1
        int freq[26] = {0};

        for(int i=0;i<s1.length();i++){
            freq[s1[i]-'a']++;
        }

        int windsize = s1.length();      //taking window of size s1

        for(int i=0;i<s2.length();i++){      //checking if the current window has same freq as the freq stored in freq array of s1
            int windidx = 0, idx = i;
            int windfreq[26] = {0};

            while(windidx<windsize && idx<s2.length()){
                windfreq[s2[idx]-'a']++;
                windidx++;
                idx++;
            }

            if(isfreqsame(freq,windfreq)){      //found
                return true;
            }
        }
        return false;
        
    }
};