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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head): head(head) {

    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int i=2;
        ListNode* cur = head->next;
        int val = head->val;
        while(cur != nullptr) {
            if(rand() % i + 1 == 1) val = cur->val; //第 i 节点以 1/i 概率替换当前值
            i++;
            cur = cur->next;
        }
        return val;
    }
private:
    ListNode* head;
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

// 第i个元素以1/i的概率选取
