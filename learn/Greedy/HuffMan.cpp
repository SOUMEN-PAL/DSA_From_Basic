#include<bits/stdc++.h>
using namespace std;

class Node {
public:

    char item;
    int freq;
    Node* left;
    Node* right;

    Node(char i, int f) {
        this->item = i;
        this->freq = f;
        left = right = NULL;
    }
};

struct myComp
{
    //operator overloading
    bool operator() (Node *a , Node *b){
        return a->freq > b->freq;
    }
};

Node* HuffmanEncoding(vector<char> arr, vector<int> freq) {
    int n = arr.size();

    priority_queue<Node*, vector<Node*> , myComp> pq;

    for(int i = 0 ; i<n ; i++){
        char item = arr[i];
        int frequency = freq[i];
        Node *temp = new Node(item , frequency);
        pq.push(temp);
    }

    while(pq.size()>1){
        Node *l = pq.top();
        pq.pop();
        Node *r = pq.top();
        pq.pop();
        Node *internalNode = new Node('$' , (l->freq + r->freq));
        internalNode->left = l;
        internalNode->right = r;
        pq.push(internalNode);
    }

    auto root = pq.top();
    pq.pop();
    return root;
}

void huffManDecode(Node *root , string str , vector<pair<char , string>> &ans){
    if(root == NULL){
        return;
    }
    if(root->item != '$'){
        ans.push_back({root->item , str});
        return;
    }

    huffManDecode(root->left , str+"0" , ans);
    huffManDecode(root->right , str+"1" , ans);
}

int main() {

    vector<char> items{'a' , 'b' , 'c' , 'd' , 'e'};
    vector<int> freq{10 , 20 , 40 , 30 , 90};

    Node *root = HuffmanEncoding(items , freq);

    vector<pair<char , string>> ans;
    huffManDecode(root , "" , ans);

    for(auto i : ans){
        cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;
}
