class StockPrice {
private: 
    map<int,int> record;
    multiset<int> prices;
        
public:
    StockPrice() {}
    
    void update(int timestamp, int price) {
        if(record.find(timestamp) != record.end())
            prices.erase(prices.find(record[timestamp])); 
        record[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return record.rbegin()->second;
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
 
 //https://leetcode.com/problems/stock-price-fluctuation/