//Given the head of a linked list, return the node where the cycle 
//begins. If there is no cycle, return null.
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        int flag=1;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                flag=0;
                break;
            }
        }
        if(flag)
            return NULL;
        fast=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        
    }
};
