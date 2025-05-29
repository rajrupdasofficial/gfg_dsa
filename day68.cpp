/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(!head || k <= 1) return head;
        
        Node* curr = head;
        Node* newHead  = nullptr;
        Node* tail = nullptr;
        
        while(curr){
            Node* groupPrev = nullptr;
            Node* groupCurr = curr;
            int count = 0;
            
            while(curr && count < k){
                Node* next = curr -> next;
                curr->next = groupPrev;
                groupPrev = curr;
                curr = next;
                count++;
            }
            if(!newHead) newHead = groupPrev;
            if (tail) tail -> next = groupPrev;
            tail = groupCurr;
        }
        return newHead;
    }
};
