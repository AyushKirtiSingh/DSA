class StockSpanner {
public:
    stack<pair<int,int>> st; 
    // pair = {price, index}; stack class ke andar hai taaki data next() calls ke beech preserve rahe

    int ans = 0;
    int idx = 0; 
    // idx = current price ka index

    StockSpanner() {
        // Constructor: object create hote time ek baar call hota hai
    }
    
    int next(int price) {
        // Har new price ke liye Stock Span calculate hota hai
        
        while(st.size()>0 && st.top().first<=price){
            // Top ka price <= current price → useless, remove
            st.pop();
        }

        if(st.size()==0){
            // Koi previous greater price nahi mila
            ans = idx + 1;
        }
        else{
            // Top = previous greater price; second = uska index
            ans = idx - st.top().second;
        }

        st.push({price,idx});
        // Current price + index future calls ke liye save

        idx++;
        // Next price ke liye index increase

        return ans;
        // Current Stock Span return
    }
};