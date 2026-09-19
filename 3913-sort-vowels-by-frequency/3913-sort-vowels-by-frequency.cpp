class Solution {
public:
    string sortVowels(string s) {
        vector<char> ans;
        vector<char> result;
        int count = 0;
        int temp = s.length();
        unordered_map<int,int> m;
        unordered_map<int,int> first;

        // Har vowel ka first occurrence index store karenge
        // aur saare vowels ko ans mein collect karenge.
        for(int i=0;i<s.length();i++){
            char x = s[i];
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
                // Agar vowel pehli baar mila hai, uska index save karo.
                if(first.find(x)==first.end()){
                    first[x] = i;
                }
                ans.push_back(x);
            }
            else{
                // temp mein sirf vowels ki count rakh rahe hain.
                temp--;
            }
            
        }

        // Har vowel ki frequency count kar rahe hain.
        for(int x : ans){
            m[x]++;
        }

        // Count kar rahe hain kitne vowels exactly 1 baar aaye hain.
        for(auto it : m){
            if(it.second==1){
                count++;
            }
        }

        // Agar har vowel unique hai, toh sabki frequency same = 1 hai.
        // Isliye first occurrence order already correct hai.
        if(count==temp){
            return s;
        }

        // pair mein:
        // first  = {frequency, -firstOccurrence}
        // second = vowel
        vector<pair<pair<int,int>,char>> v;

        // Frequency aur first occurrence dono store kar rahe hain.
        for(auto it : m){
            v.push_back({{it.second,-first[it.first]},it.first});
        }

        // Pehle higher frequency,
        // aur same frequency par earlier first occurrence.
        sort(v.begin(),v.end(),greater<pair<pair<int,int>,char>>());



        // Sorted frequency ke according vowels ka result bana rahe hain.
        for(int i=0;i<v.size();i++){
            int j=1;
            while(j<=v[i].first.first){
                result.push_back(v[i].second);
                j++;
            }
        }

        int j = 0;

        // Original string mein sirf vowel positions ko
        // sorted result ke vowels se replace karenge.
        for(int i=0;i<s.length();i++){
            if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u'){
                continue;
            }
            else{
                s[i] = result[j];
                j++;
                
            }
        }

        return s;
    }
};            

