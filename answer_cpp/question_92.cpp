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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        auto dummy=new ListNode(-1);
        dummy->next=head;
        auto a=dummy,d=dummy;
        for(int i=0;i<m-1;i++) a=a->next;
        for(int i=0;i<n;i++) d=d->next;
        auto b=a->next,c=d->next;
        for(auto p=b,q=p->next;q!=c;){
            auto o=q->next;
            q->next=p;
            p=q;q=o;
        }
        a->next=d;
        b->next=c;
        return dummy->next;
    }
};

