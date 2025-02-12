/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            ListNode* Dummy1 = new ListNode(-1);
            ListNode* Temp1 = Dummy1;
            ListNode* Dummy2 = new ListNode(-1);
            ListNode* Temp2 = Dummy2;
            ListNode* List = head;
            int Cnt = 0;
            while (List != NULL) {
                if (Cnt % 2 == 0) {
                    Temp1->next = new ListNode(List->val);
                    Temp1 = Temp1->next;
                } else {
                    Temp2->next = new ListNode(List->val);
                    Temp2 = Temp2->next;
                }
                Cnt += 1;
                List = List->next;
            }
            Temp1->next = Dummy2->next;
            return Dummy1->next;
        }
    };