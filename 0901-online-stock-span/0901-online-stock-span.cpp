class StockSpanner {
private:
    // Stores {price, span} in strictly decreasing order of price
    stack<pair<int, int>> st;

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        
        // Merge spans of all consecutive previous days with price <= today
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        st.push({price, span});
        return span;
    }
};
