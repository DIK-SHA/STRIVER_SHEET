// Rotate List
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
// Input: head = [0,1,2], k = 10
// Output: [2,0,1]

class Solution {
public:
    // ListNode* rotateRight(ListNode* head, int k) {
    //     if(head==NULL || k==0)
    //         return head;
    //     ListNode* curr=head;
    //     ListNode* dummy=curr;
    //     ListNode* prev=NULL;
    //     ListNode* n;
    //     int size=0;
    //     ListNode* temp=head;
    //     while(temp){
    //         size++;
    //         temp=temp->next;
    //     }
    //     while(k>size)
    //         k=k-size;
    //     if(k==size)
    //         return head;
    //     k=size-k;
    //     while(curr && k--){
    //         n=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=n;
    //     }
    //     head=prev;
    //     prev=NULL;
    //     while(curr){
    //         n=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=n;
    //     }
    //     dummy->next=prev;
    //     curr=head;
    //     prev=NULL;
    //     while(curr){
    //         n=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=n;
    //     }
    //     return prev;
    // }
    
    ListNode* rotateRight(ListNode* head, int k){
        if(head==NULL || k==0)
            return head;
        ListNode* curr=head;
        ListNode* dummy=curr;
        ListNode* n;
        int size=0;
        ListNode* temp=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        while(k>size)
        k=k-size;
        if(k==size)
            return head;
        temp=head;
        for(int i=1;i<size-k;i++){
            temp=temp->next;
        }
        n=temp->next;
        temp->next=NULL;
        head=n;
        while(n->next){
            n=n->next;
        }
        n->next=dummy;
        return head;
    }
    
};
