class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz=flowerbed.size();
        if(n==0) return true;
        if(sz==1)
        {
            if(flowerbed[0]==0 && n==1) return true;
            else return false;
        }
        for(int i=0;i<sz;i++)
        {
            if(i==0)
            {
                if(flowerbed[i+1]==0 && flowerbed[i]==0)
                {
                    flowerbed[i]=1;
                    n--;
                    if(n==0) return true;
                }
            }
            else if(i==sz-1)
            {
                if(flowerbed[i-1]==0 && flowerbed[i]==0)
                {
                    flowerbed[i]=1;
                    n--;
                    if(n==0) return true;

                }
            }
            else if(flowerbed[i-1]==0 && flowerbed[i+1]==0 && flowerbed[i]==0)
            {
                flowerbed[i]=1;
                n--;
                if(n==0) return true;

            }
        }
        if(n==0)
        {
            return true;
        }
        return false;
    }
};