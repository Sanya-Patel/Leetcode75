class Solution {
    public:
        int pairSum(ListNode* head) {
            vector<int>v;
            while(head!=NULL)
            {
                v.push_back(head->val);
                head=head->next;
            }
            int n=v.size();
            int i=0,j=n-1;
            int maxi=0;
            while(i<j)
            {
                maxi=max(maxi,v[i]+v[j]);
                i++;
                j--;
            }
            return maxi;
        }
    };