class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0, head);

        ListNode* cur = dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};

// fake_head 想到了 next指向head
// cur 想到了
// 继续加当前值变量就做出来了
// 换头：cur->next = cur->next->next; 此时若为第一次操作，操作的便是dummy->next
// 不换头：cur = cur->next; 此时cur已经不是dummy了，再操作不影响dummy的位置
