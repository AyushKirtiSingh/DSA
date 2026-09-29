class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t); // Current request ko queue mein add karo

        int low = t - 3000; // Valid time window ki lower limit

        while(!q.empty() && q.front()<low){
            q.pop(); // 3000ms se purane requests remove karo
        }

        return q.size(); // Current 3000ms window mein total requests
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */