//Clone a Linked List with random and next pointer
class Solution {
public:
    Node* copyRandomList(Node* head) {
        auto it=head;
        auto front=head;
        while(it){
            front=it->next;
            auto copy=new Node(it->val);
            it->next=copy;
            copy->next=front;
            it=front;
        }
        it=head;
        while(it && it->next){
            if(it->random){
                it->next->random=it->random->next;
            }
            it=it->next->next;
        }
        it=head;
        auto dummy=new Node(0);
        auto copy=dummy;
        while(it && it->next){
            front=it->next->next;
            copy->next=it->next;
            it->next=front;
            copy=copy->next;
            it=it->next;
        }
        return dummy->next;
    }
};