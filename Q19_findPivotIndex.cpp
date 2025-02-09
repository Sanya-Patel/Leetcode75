class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            int n = nums.size();
            int LeftSum = 0;
            int RightSum = 0;
            for (int i = 0; i < n; i++) {
                LeftSum = 0;
                RightSum = 0;
                for (int j = 0; j < i; j++) {
                    LeftSum += nums[j];
                }
                for (int k = i + 1; k < n; k++) {
                    RightSum += nums[k];
                }
                if (LeftSum == RightSum) {
                    return i;
                }
            }
            return -1;
        }
    };