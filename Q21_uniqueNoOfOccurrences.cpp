class Solution {
    public:
        bool uniqueOccurrences(vector<int>& arr) {
            unordered_map<int, int> mp;
            vector<int> v;
            int n = arr.size();
            for (int i = 0; i < n; i++) {
                mp[arr[i]]++;
            }
            for (auto i : mp) {
                v.push_back(i.second);
            }
            sort(v.begin(), v.end());
            int m = v.size();
            for (int i = 0; i < m - 1; i++) {
                if (v[i] == v[i + 1]) {
                    return false;
                }
            }
            return true;
        }
    };