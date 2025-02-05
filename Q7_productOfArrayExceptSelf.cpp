class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0,ans=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zero++;
            }
            else
            {
                ans*=nums[i];
            }
        }
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            if(zero==0)
            {
                v.push_back(ans/nums[i]);
            }
            else if(zero==1 && nums[i]==0)
            {
                v.push_back(ans);
            }
            else
            {
                v.push_back(0);
            }
        }
        return v;
    }
};