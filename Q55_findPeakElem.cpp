class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int maxi=*max_element(nums.begin(),nums.end());
            int  n=nums.size();
            for(int i=0;i<n;i++)
            {
                if(nums[i]==maxi)
                {
                    return i;
                }
            }
            return -1;
        }
    };