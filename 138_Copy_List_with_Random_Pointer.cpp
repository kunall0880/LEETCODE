class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*>mp;
        Node * nhead=NULL,*prev=NULL,*curr=head;
        //next pointer
        while(curr!=NULL){
            Node *temp=new Node(curr->val);
            mp[curr]=temp;
            if(prev==NULL){
                nhead=temp;
                prev=nhead;
            }else{
                prev->next=temp;
                prev=temp;
            }
            curr=curr->next;
        }
        //random pointers
        curr=head;
        Node *ncurr=nhead;
        while(curr!=NULL){
            if(curr->random==NULL){
                ncurr->random=NULL;
            }else{
                ncurr->random=mp[curr->random];
            }
            curr=curr->next;
            ncurr=ncurr->next;
        }
        return nhead;
    }
};