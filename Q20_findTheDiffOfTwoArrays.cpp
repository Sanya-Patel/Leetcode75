class Solution {
    public:
        vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
            vector<vector<int>> ans;
            vector<int> v;
            set<int> st;
            int n = nums1.size();
            int m = nums2.size();
            bool check = true;
            for (int i = 0; i < n; i++) {
                check = true;
                for (int j = 0; j < m; j++) {
                    if (nums1[i] == nums2[j]) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    st.insert(nums1[i]);
                }
            }
            // vector<int>v(st.begin(), st.end());
            v.assign(st.begin(), st.end());
            ans.push_back(v);
            st.clear();
            for (int i = 0; i < m; i++) {
                check = true;
                for (int j = 0; j < n; j++) {
                    if (nums2[i] == nums1[j]) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    st.insert(nums2[i]);
                }
            }
            v.assign(st.begin(), st.end());
            ans.push_back(v);
    
            return ans;
        }
    };