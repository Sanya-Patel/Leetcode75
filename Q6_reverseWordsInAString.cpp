class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        bool f=0;
        string st="";
        vector<string>v;
        int idx=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                idx=i;
                break;
            }
        }
        for(int i=0;i<=idx;i++)
        {
            if(s[i]!=' ')
            {
                f=1;
            }
            if(s[i]!=' ' && f==1)
            {
                st+=s[i];
            }
            else if(f==1)
            {
                if(st!="")
                    v.push_back(st);
                st="";
            }
        }
        v.push_back(st);
        string ans="";
        int sz=v.size();
        for(int i=sz-1;i>=0;i--)
        {
            // cout<<i<<"-"<<endl;
            // if(v[i]!=" ")
            // {
                ans+=v[i];
                ans+=" ";
            // }
        }
        // reverse(ans.begin(),ans.end());
        ans.pop_back();
        return ans;
    }
};