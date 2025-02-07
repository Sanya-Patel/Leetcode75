class Solution {
public:
    bool check(char &ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int maxi=0;
        int n=s.size();
        int i=0,j=0;
        int c=0;
        while(j<n)
        {
            if(check(s[j]))
            {
                c++;
            }
            if(j-i+1==k)
            {
                maxi=max(maxi,c);
                if(check(s[i]))
                {
                    c--;
                }
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return maxi;
    }
};