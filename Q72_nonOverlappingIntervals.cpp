class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            int i=0,j=1;
            int c=0;
            int n=intervals.size();
            sort(intervals.begin(),intervals.end());
            while(j<n)
            {
                int cs=intervals[i][0];
                int ce=intervals[i][1];
    
                int ns=intervals[j][0];
                int ne=intervals[j][1];
    
                if(ce<=ns)
                {
                    i=j;
                    j++;
                }
                else if(ce<=ne)
                {
                    c++;
                    j++;
                }
                else if(ce>ne)
                {
                    i=j;
                    j++;
                    c++;
                }
            }
            return c;
        }
    };