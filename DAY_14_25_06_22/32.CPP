//Linked List Cycle
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *s=head;
        ListNode *f=head;
        if(head==NULL || head->next==NULL)
            return false;
        while(f && f->next)
        {
            s=s->next;
            f=f->next->next;
            if(s==f)
                return true;
        }
        return false;
    }
};