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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            if (fast->val != slow->val) {
                // nums[slow] = nums[fast];
                slow->next = fast;
                // slow++;
                slow = slow->next;
            }
            // fast++
            fast = fast->next;
        }
        // 断开与后面重复元素的连接
        slow->next = nullptr;
        return head;
    }
};
