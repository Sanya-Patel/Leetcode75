class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        int n=word1.size(), m=word2.size();
        string ans="";
        bool ch=0;
        while(i<n && j<m)
        {
            if(ch==false)
            {
                ans+=word1[i];
                i++;
                ch=1;
            }
            else
            {
                ans+=word2[j];
                j++;
                ch=0;
            }
        }
        while(i<n)
        {
            ans+=word1[i];
            i++;
        }
        while(j<m)
        {
            ans+=word2[j];
            j++;
        }
        return ans;
    }
};