//Reverse Nodes in k-Group
class Solution {
public:
    
    ListNode* solve(ListNode* curr, int k, int size, int times)
    {
        if(times>=size || curr==NULL)
            return curr;
        ListNode* n;
        ListNode* prev=NULL;
        ListNode* dummy=curr;
        int x=k;
        while(curr && x-- ){
            n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        dummy->next=solve(curr, k, size, times+1);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        size=size/k;
        return solve(head, k , size, 0);
    }
};

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]