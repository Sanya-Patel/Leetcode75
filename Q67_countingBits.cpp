class Solution {
    public:
        int count(int i)
        {
            int cnt=0;
            while(i)
            {
                if(i%2==1)
                {
                    cnt++;
                }
                i=i/2;
            }
            return cnt;
        }
        vector<int> countBits(int n) {
            vector<int>v;
            for(int i=0;i<=n;i++)
            {
                v.push_back(count(i));
            }
            return v;
        }
    };