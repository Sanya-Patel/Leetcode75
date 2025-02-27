class StockSpanner {
    public:
        StockSpanner() {}
    
        stack<pair<int,int>> s1;
       // int ans =1;
        
        int next(int price) {
              int ans =1;
              if( s1.empty()){
                  
                  s1.push({price,ans});
                  return ans ;
    
              }
              else {
    
                 while ( !s1.empty() && s1.top().first<=price){
    
                    ans = ans + s1.top().second;
                    s1.pop();
                 }
                 s1.push({price,ans});
                 return ans ;
              }
    
    
    
        }
    };
    
    /**
     * Your StockSpanner object will be instantiated and called as such:
     * StockSpanner* obj = new StockSpanner();
     * int param_1 = obj->next(price);
     */