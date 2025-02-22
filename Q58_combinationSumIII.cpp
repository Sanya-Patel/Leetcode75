class Solution {
    public:
        void solve(int start, int& sum, int& k, int& n, vector<int>& v,
                   vector<vector<int>>& ans) {
            if (sum == n and v.size() == k) {
                ans.push_back(v);
                return;
            }
            if (sum > n or v.size() > k) {
                return;
            }
            for (int i = start; i <= 9; i++) {
                sum += i;
                v.push_back(i);
                solve(i + 1, sum, k, n, v, ans);
                v.pop_back();
                sum -= i;
            }
        }
        vector<vector<int>> combinationSum3(int k, int n) {
            vector<vector<int>> ans;
            vector<int> v;
            int sum = 0;
            int start = 1;
            solve(start, sum, k, n, v, ans);
            return ans;
        }
    };