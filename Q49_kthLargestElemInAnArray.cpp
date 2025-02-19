class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int, vector<int>, greater<int>> minH;
            for (int i = 0; i < k; i++) {
                minH.push(nums[i]);
            }
            int element;
            for (int i = k; i < nums.size(); i++) {
                element = nums[i];
                if (minH.top() < element) {
                    minH.pop();
                    minH.push(element);
                }
            }
            return minH.top();
        }
    };