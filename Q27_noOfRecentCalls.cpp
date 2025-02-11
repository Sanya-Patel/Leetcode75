class RecentCounter {
    public:
        vector<int>p;
        RecentCounter() {
            
        }
        
        int ping(int t) {
            int n=p.size();
            if(n==0)
            {
                p.push_back(t);
                return p.size();
            }
            p.push_back(t);
            // int cnt=0;
            int cnt=1;
            for(int i=n-1;i>=0;i--)
            {
                if(p[i]<(t-3000))
                {
                    break;
                }
                else
                {
                    cnt++;
                }
            }
            return cnt;
        }
    };
    
    /**
     * Your RecentCounter object will be instantiated and called as such:
     * RecentCounter* obj = new RecentCounter();
     * int param_1 = obj->ping(t);
     */