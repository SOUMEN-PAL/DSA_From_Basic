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
        Node *next;
        Node *prev;

        Node(int d){
            data = d;
            next = NULL;
            prev = NULL;
        }
};

void Traverse(Node *head){
    if(head == NULL){
        cout<<"Empty"<<endl;
    }
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* insertEnd(Node* head , int x){
    Node* temp = new Node(x);
    if(head == NULL){
        return temp;
    }
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    return head;
}

int main(){
    Node* head = new Node(10);
    Node* t1 = new Node(20);
    Node* t2 = new Node(30);
    head->next = t1;
    t1->prev = head;
    t1->next = t2;
    t2->prev = t1;
    Traverse(head);
    head = insertEnd(head , 40);
    Traverse(head);
    return 0;
}