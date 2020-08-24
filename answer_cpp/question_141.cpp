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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode* fast{head};
        ListNode* slow{head};
        // ListNode *fast, *slow; // 第二个‘*’不能省略
        // fast = slow = head;
        while (fast!=nullptr && fast->next!=nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};

// 注意定义指针时 *是修饰变量 而不是修饰类型本身
// copy指针的两种方式
