
// struct Node {
//     int data;
//     struct Node *next;
//     Node(int x) {
//         data = x;
//         next = NULL;
//     }
// };


class Solution {
public:
    Node* rotate(Node* head, int k) {
        // Your code here
        if(!head || !head->next || k==0) return head;
        Node* tail = head;
        int len = 1;
        while(tail->next){
            tail = tail->next;
            len++;
        }
        k=k%len;
        if(k==0) return head;

        Node* newTail = head;

        for(int i = 1;i< k;i++){
            newTail = newTail -> next;
        }
        Node* newHead = newTail -> next;
        newTail ->next = nullptr;
        tail -> next = head;
        return newHead;
    }
};
