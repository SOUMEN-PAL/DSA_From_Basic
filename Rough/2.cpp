#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

   struct Node* insert(struct Node* head , int x){
        struct Node* temp = new Node(x);
        if(head == NULL){
            return temp;
        }
        struct Node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
        return head;
    }
    
    struct Node* reverse(struct Node *head)
    {
        Node* curr = head;
        Node* next = head;
        Node* pre = NULL;
        while(curr != NULL){
            curr = curr->next;
            next->next = pre;
            pre = next;
            next = curr;
        }
        return pre;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {   
        
        struct Node* res = NULL;
        first = reverse(first);
        second = reverse(second);
        
         int carry = 0;  // Initialize carry outside the loop

    while (first != NULL || second != NULL || carry != 0) {
        int sum = (first ? first->data : 0) + (second ? second->data : 0) + carry;
        
        if (sum < 10) {
            res = insert(res, sum);
            carry = 0;
        } else {
            res = insert(res, sum % 10);
            carry = sum / 10;
        }

            if(first != NULL){
                first = first->next;
            }
            if(second != NULL){
                second = second->next;
            }
            
        }
        
        res = reverse(res);
        return res;
        
    }

int main(){

    Node* head1 = new Node(1);
    head1->next = new Node(0);
    head1->next->next = new Node(1);

    Node* head2 = new Node(1);
    head2->next = new Node(0);
    head2->next->next = new Node(9);

    Node* res = addTwoLists(head1 , head2);

    while(res != NULL){
        cout<<res->data<<" ";
        res = res->next;
    }

    return 0;
}