class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int out = 0;
        while (head != nullptr) {
            out = (out << 1) | head->val;
            head = head->next;
        }
        return out;
    }
};
