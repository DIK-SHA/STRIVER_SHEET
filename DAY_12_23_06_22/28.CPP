// Remove Nth Node From End of List
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Also check the previous submission od this
        ListNode* slow=head;
        ListNode* fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==NULL){
            return head->next;
        }
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};

//THIS WAS MINE
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL && n==1){
            delete(head);
            return NULL;
        }
        ListNode* slow=head;
        ListNode* prev=NULL;
        ListNode* fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast){
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        if(slow==head){
            head=head->next;
            delete slow;
            return head;
        }
        prev->next=slow->next;
        delete(slow);
        return head;
    }
};