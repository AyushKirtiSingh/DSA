class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> m;
        string ans = "";

        // Har character ki frequency count kar rahe hain
        for(char x : s){
            if(m.find(x)==m.end()){
                m[x] = 1;
            }
            else{
                m[x]++;
            }
        }
        unordered_map<int,int> q;

        // Har frequency kitne characters ki hai, wo count kar rahe hain
        for(auto it : m){
            if(q.find(it.second)==q.end()){
                q[it.second]=1;
            }
            else{
                q[it.second]++;
            }
        }

        int maxi = 0;
        int freq = 0;

        // Maximum characters wali frequency find kar rahe hain
        // Tie ho toh larger frequency choose karenge
        for(auto it : q){
            if(it.second > maxi || (it.second == maxi && it.first > freq)){
                maxi = it.second;
                freq = it.first;
            }
        }

        set<char> str;

        // Unique characters ko set mein store kar rahe hain
        for(char x : s){
            str.insert(x);
        }

        // Sirf winning frequency wale characters answer mein add kar rahe hain
        for(char x : str){
            if(m[x]==freq){
                ans += x;
            }
        }

        return ans;
    }
};

