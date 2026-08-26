class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ans = 0;
    int idx = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        while(st.size()>0 && st.top().first<=price){
            st.pop();
        }

        if(st.size()==0){
            ans = idx + 1;
        }
        else{
            ans = idx - st.top().second;
        }

        st.push({price,idx});
        idx++;

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */