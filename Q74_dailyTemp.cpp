class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
         
    stack<pair<int, int>> s;
    vector<int>v;
    
    int size = temperatures.size();
    for (int i = size - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            v.push_back(0);
            s.push({temperatures[i], i});
        }
        else if (s.size() > 0 and s.top().first > temperatures[i])
        {
            v.push_back(s.top().second);
            s.push({temperatures[i], i});
        }
        else if (s.size() > 0 and s.top().first <= temperatures[i])
        {
            while (s.size() > 0 and s.top().first <= temperatures[i])
            {
                s.pop();
            }
                if (s.size() == 0)
                {
                    v.push_back(0);
                    s.push({temperatures[i], i});
                }
                else
                {
                    v.push_back(s.top().second);
                    s.push({temperatures[i], i});
                }
            }
        }
    
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]==0)
        {
             v[i]=0;
        }
        else
        { 
        v[i] = v[i]-i;
        }
    }
    return v;
    }   
        
    };