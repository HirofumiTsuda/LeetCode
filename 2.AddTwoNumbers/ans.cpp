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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // head of list;
        ListNode* head = new ListNode(0);
        int carry = 0;  // carry bit
        ListNode* curr = new ListNode(0);
        head->next = curr;
        // do until both l1 and l2 reache NULL
        while (l1 != nullptr || l2 != nullptr) {
            // if l1 or l2 is null, then its value is set 0
            int l1_val = (l1 != nullptr)? l1->val : 0;
            int l2_val = (l2 != nullptr)? l2->val : 0;
            int sum = l1_val + l2_val + carry;
            curr->val = sum%10;
            carry = (int)(sum/10);
            if(l1 != nullptr){
                l1 = l1->next;
            }
            
            if(l2 != nullptr){
                l2 = l2->next;
            }
            
            // end
            if(l1 != nullptr || l2 != nullptr){
                ListNode* next = new ListNode(0);
                curr->next = next;
                curr = next;
            }
            if(l1 == nullptr && l2 == nullptr && carry == 1){
                ListNode* next = new ListNode(1);
                curr->next = next;
                curr = next;
            }
            
        }

        
        // answer is head->next (head is meaningless)
        return head->next;
    }
};
