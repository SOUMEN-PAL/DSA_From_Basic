#include<bits/stdc++.h>
using namespace std;

// Define Node structure
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int d) {
        data = d;
        next = NULL;
    }
};

void Traverse(Node *head){
    for(auto curr = head ; curr != NULL ; curr = curr->next ){
        cout<<curr->data<<" ";
    }
    cout<<endl;
}


// Naive solution //
bool isPalindrome(Node *head){
    
    if(head == NULL || head->next == NULL){
        return true;
    }

    stack<int> st;
    for(auto curr = head ; curr != NULL ; curr = curr->next){
        st.push(curr->data);
    }

    for(auto curr = head ; curr != NULL ; curr = curr->next){
        if(st.top() != curr->data){
            return false;
        }
        st.pop();
    }
    return true;
}


// Efficient solution TC : O(n) AS : O(1) //
//
Node *mid(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
// Utility Function //
Node* reverse(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node *next = NULL , *prev = NULL , *curr = head;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
//
bool isPlaindromeList(Node *head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node*m = mid(head);
    Node *nextToMid = m->next;
    m->next = NULL;
    Node *secondHalf = reverse(nextToMid);
    Node *firstHalf = head;


    while(secondHalf != NULL){
        if(firstHalf->data != secondHalf->data){          
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;


}


int main(){
    
    Node *head = new Node(10);
    Node *h2 = new Node(20);
    Node *h3 = new Node(20);
    Node *h4 = new Node(10);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;

    if(isPlaindromeList(head)){
        cout<<"Palindrome list"<<endl;
    }
    else{
        cout<<"Not a palindrome"<<endl;
    }



    return 0;
}