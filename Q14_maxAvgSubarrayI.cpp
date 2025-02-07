class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double maxi=INT_MIN;
        double s=0;
        int i=0,j=0;
        while(j<n)
        {
            s+=nums[j];
            if(j-i+1==k)
            {
                double temp=s/k;
                maxi=max(maxi,temp);
                s-=nums[i];
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