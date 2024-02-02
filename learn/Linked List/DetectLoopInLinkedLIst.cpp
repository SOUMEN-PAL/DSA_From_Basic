#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next = NULL;
    bool visited;
    Node(int d){
        data = d;
        next = NULL;
        visited = false;
    }
};

// Good Solution but destroys the linked list//
bool isLoop(Node *head){
    Node* curr = head , *temp = new Node(0);
    while(curr != NULL){
        if(curr->next == NULL){
            return false;
        }
        else if(curr->next == temp){
            return true;
        }
        Node* curr_next = curr->next;
        curr->next = temp;
        curr = curr_next;
    }
    return false;
}

// method 4 hashing //

bool isLoopHashing(Node *head){
    unordered_set<Node*> hs;

    Node *curr = head;
    while(curr != NULL){
        if(hs.find(curr) != hs.end()){
            return true;
        }

        hs.insert(curr);
    }
    return false;
}

//Method 5 floys warsel //

bool isLoopTor(Node *head){
    Node *slow = head , *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

int firstNodeOfLoop(Node *head){
    Node *slow = head;
    Node *fast = head;

    do{
        if(fast == NULL || fast->next == NULL){
            return -1;
        }
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast);

    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}

int main(){
    Node *head = new Node(10);
    Node *h2 = new Node(20);
    Node *h3 = new Node(30);
    Node *h4 = new Node(40);
    Node *h5 = new Node(50);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h2;

    if(isLoopTor(head)){
        cout<<"Loop detected at: "<<firstNodeOfLoop(head)<<endl;
    }else{
        cout<<"Loop not present"<<endl;
    }

    

    return 0;
}