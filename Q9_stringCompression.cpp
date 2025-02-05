class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int idx=0;
        for(int i=0;i<n;i++)
        {
            int j=i;
            int c=0;
            char ch=chars[i];
            while(j<n && chars[j]==ch)
            {
                c++;
                j++;
            }
            i=j;
            if(c==1)
            {
                chars[idx++]=ch;
            }
            else
            {
                chars[idx++]=ch;
                string temp=to_string(c);
                for(char c:temp)
                {
                    chars[idx++]=c;
                }
            }
            i--;  //because extra i++ of for loop happens so reduce i by 1
        }
        return idx;
    }
};