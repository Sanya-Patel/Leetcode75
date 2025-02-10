class Solution {
    public:
        bool closeStrings(string word1, string word2) {
            if(word1.size()!=word2.size()) return false;
            unordered_map<char,int>mp1, mp2;
            for(char ch:word1)
            {
                mp1[ch]++;
            }
            for(char ch:word2)
            {
                mp2[ch]++;
            }
            vector<int>v1,v2;
            vector<char>v3,v4;
            for(auto i:mp1)
            {
                v3.push_back(i.first);
                v1.push_back(i.second);
            }
            for(auto i:mp2)
            {
                v4.push_back(i.first);
                v2.push_back(i.second);
            }
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());
            sort(v3.begin(),v3.end());
            sort(v4.begin(),v4.end());
            for(int i=0;i<v1.size();i++)
            {
                if(v3[i]!=v4[i])
                {
                    return false;
                }
                if(v1[i]!=v2[i])
                {
                    return false;
                }
            }
            return true;
        }
    };