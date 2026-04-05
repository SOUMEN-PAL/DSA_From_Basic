#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;


class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
};


void traverse(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


Node *reverse(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *newHead = reverse(head->next);
    Node* tail = head->next;
    tail->next = head;
    head->next = NULL;
    return newHead;
}

int main(){
    Node* head = new Node(10);
    Node* h2 = new Node(20);
    Node* h3 = new Node(30);
    Node* h4 = new Node(40);
    Node* h5 = new Node(50);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    
    traverse(head);
    cout<<endl;
    head = reverse(head);
    traverse(head);
    

    return 0;
}