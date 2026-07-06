class Solution {
public:
    int minPartitions(string n) {
        char max_char = *max_element(begin(n),end(n));

        return max_char - '0';
    }
};