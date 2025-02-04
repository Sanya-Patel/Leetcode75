class Solution {
public:
    bool check(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
        {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        vector<char>vow1;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(check(s[i]))
            {
                vow1.push_back(s[i]);
            }
        }
        vector<char>vow2(vow1.begin(),vow1.end());
        reverse(vow2.begin(),vow2.end());
        int k=0;
        for(int i=0;i<n;i++)
        {
            // cout<<s[i]<<" "<<vow1[k]<<endl;
            if(k<vow1.size() && s[i]==vow1[k])
            {
                s[i]=vow2[k];
                k++;
            }
        }
        return s;
    }
};