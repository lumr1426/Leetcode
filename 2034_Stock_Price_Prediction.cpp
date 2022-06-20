#2034 Stock price prediction
#Difficulty: Medium
#You are given a stream of records about a particular stock. Each record contains a timestamp and the corresponding price of the stock at that timestamp.

#Unfortunately due to the volatile nature of the stock market, the records do not come in order. Even worse, some records may be incorrect. Another record with the same timestamp may appear later in the stream correcting the price of the previous wrong record.

#Design an algorithm that:

#Updates the price of the stock at a particular timestamp, correcting the price from any previous records at the timestamp.
#Finds the latest price of the stock based on the current records. The latest price is the price at the latest timestamp recorded.
#Finds the maximum price the stock has been based on the current records.
#Finds the minimum price the stock has been based on the current records.
#Implement the StockPrice class:

#StockPrice() Initializes the object with no price records.
#void update(int timestamp, int price) Updates the price of the stock at the given timestamp.
#int current() Returns the latest price of the stock.
#int maximum() Returns the maximum price of the stock.
#int minimum() Returns the minimum price of the stock.

###Optimal Solution
class StockPrice {
public:
    
    map<int,int> time_stock;
    multiset<int> prices; 
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(time_stock.find(timestamp)!=time_stock.end())
        {
            prices.erase(prices.find(time_stock[timestamp]));
        }
        time_stock[timestamp]=price;
        prices.insert(price);
    }
    
    int current() {
        return time_stock.rbegin()->second;
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

#1. map was used to link timestamp and the corresponding price.
#2. Used map and NOT unordered_map to find the latest timestamp and fetch that price for recent function
#3. Used multiset to store prices that exist. Why multiset and not set? => because there can be multiple same prices in stock,
# and if you use set, then when thre is multiple same maximum and update one maximum, the info will be gone.
