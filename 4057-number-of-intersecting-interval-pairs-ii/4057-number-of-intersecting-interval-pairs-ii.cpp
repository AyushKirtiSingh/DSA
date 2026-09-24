class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {

        // Starting point ke according intervals sort karo
        sort(intervals.begin(), intervals.end());

        // Previous active intervals ke END points store honge
        // Min-heap: sabse chhota end sabse upar
        priority_queue<int, vector<int>, greater<int>> pq;

        long long ans = 0;

        for(auto &x : intervals) {

            // Jo intervals current interval ke start
            // hone se pehle khatam ho chuke hain,
            // unko remove karo
            while(!pq.empty() && pq.top() < x[0])
                pq.pop();

            // Heap mein jitne intervals bache hain,
            // woh current interval ke saath intersect karenge
            ans += pq.size();

            // Current interval ka end future ke liye store karo
            pq.push(x[1]);
        }

        return ans;
    }
};