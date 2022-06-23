class StockPrice {
    map<int, int> mp;
    multiset<int> values;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.count(timestamp)>0) {
            values.erase(values.find(mp[timestamp]));
        }
        mp[timestamp] = price;
        values.insert(price);
    }
    
    int current() {
        return mp.rbegin()->second;
        
    }
    
    int maximum() {
        return *(values.rbegin());
    }
    
    int minimum() {
        return *(values.begin());
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