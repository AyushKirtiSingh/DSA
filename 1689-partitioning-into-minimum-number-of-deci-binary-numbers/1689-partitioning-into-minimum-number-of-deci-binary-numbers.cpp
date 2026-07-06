class Solution {
public:
    int minPartitions(string n) {
        int count = 0;

        while (true) {
            bool changed = false;

            for (char &ch : n) {
                if (ch != '0') {
                    ch--;          // subtract 1
                    changed = true;
                }
            }

            if (changed==false)
                break;

            count++;
        }

        return count;
    }
};