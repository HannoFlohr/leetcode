class StockSpanner {
private: 
    stack<pair<int,int>> stock_span;
public:
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        
        while(!stock_span.empty() && stock_span.top().first <= price) {
            span += stock_span.top().second;
            stock_span.pop();
        }
        
        stock_span.push({price, span});
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
 
 //https://leetcode.com/problems/online-stock-span/