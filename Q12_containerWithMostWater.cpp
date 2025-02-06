class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxi=INT_MIN;
        int i=0,j=n-1;
        while(i<j)
        {
            int width=j-i;
            int water=width*min(height[i],height[j]);
            maxi=max(maxi,water);
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxi;
    }
};