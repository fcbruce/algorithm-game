/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //l1 = reverse(l1);
        //l2 = reverse(l2);
        ListNode* head = nullptr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            if (l1 != nullptr) carry += l1->val;
            if (l2 != nullptr) carry += l2->val;
            ListNode* temp = new ListNode(carry % 10);
            temp->next = head;
            head = temp;
            carry /= 10;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        head = reverse(head);
        return head;
    }
    ListNode* reverse(ListNode* l1) {
        ListNode* head = nullptr;
        while (l1 != nullptr) {
            ListNode* temp = l1;
            l1 = l1->next;
            temp->next = head;
            head = temp;
        }
        return head;
    }
};
