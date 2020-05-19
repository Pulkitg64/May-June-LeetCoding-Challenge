class StockSpanner {

public:
    stack<int> s;
    stack<int> index;

    StockSpanner() {
        
    }
    
    int next(int price) {
       
        if(s.empty()||s.top()>price)
        {
            index.push(1);
            s.push(price);
            return 1;
        }
        int count=1;
        while(!s.empty() && s.top()<=price)
        {
            count+=index.top();
            s.pop();
            index.pop();
        }
        

        
        s.push(price);
        index.push(count);
        
        return count;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */