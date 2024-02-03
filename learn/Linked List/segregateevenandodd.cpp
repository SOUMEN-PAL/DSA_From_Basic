#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

void Traverse(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


Node* segregateEvenOdd(Node* head) {
    Node* es = NULL, * ee = NULL, * os = NULL, * oe = NULL;
    Node* curr = head;
    while (curr != NULL) {
        int x = curr->data;
        if (x % 2 == 0) {
            if (es == NULL) {
                es = ee = curr;
            }
            else {
                ee->next = curr;
                ee = ee->next;
            }
        }
        else {
            if (os == NULL) {
                os = oe = curr;
            }
            else {
                oe->next = curr;
                oe = oe->next;
            }
        }
        curr = curr->next;
    }
    if (os == NULL || es == NULL) {
        return head;
    }

    ee->next = os;
    oe->next = NULL;
    return es;

}

int main() {

    Node* head = new Node(17);
    Node* h2 = new Node(15);
    Node* h3 = new Node(8);
    Node* h4 = new Node(12);
    Node* h5 = new Node(10);
    Node* h6 = new Node(5);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;

    Traverse(head);
    head = segregateEvenOdd(head);
    Traverse(head);

    return 0;
}