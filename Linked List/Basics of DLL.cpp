#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1, Node* next1){
        data1 = data;
        next1 = next;
        back1 = back;
    }
    public:
    Node(int data1){
        data1 = data;
        next = nullptr;
        back1 = nullptr;
    }
};

Node* convertarr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteHead(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr; 
    }

    Node* prev = head;      
    head = head->next;    

    head->back = nullptr;   
    prev->next = nullptr;  

    return head;          
}

Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;  
    }
    
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;   // Traverse to the last node (tail)
    }
    
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;  
    
    return head;
}

Node* removeKthElement(Node* head, int k){
    if(head==NULL){
        return NULL;
    }
    int count = 0;
    Node* kNode = head;
    while(kNode!=NULL){
        count++;
        if(count==k){
            break;
        }
        kNode = kNode->next;
    }
    Node* prev = kNode->back;
    Node* front = kNode->next;
    
    if(prev==NULL && front == NULL){
        delete kNode;
        return NULL;
    }
    else if (prev==NULL){
        return deleteHead(head);
    }
    else if(front == NULL){
        return deleteTail(head);
    }
    
    prev->next = front;
    front->back = prev;
    
    kNode->next = NULL;
    kNode->back = NULL;
    
    delete kNode;
    
    return head;
}

// Insertion

Node* insertBeforeHead(Node* head, int val){
    // Create new node with data as val
    Node* newHead = new Node(val , head, nullptr);
    head->back = newHead;
    
    return newHead;
}

Node* insertBeforeTail(Node* head, int val){
    if(head->next==NULL){
        // If only one element
        return insertBeforeHead(head, val);
    }
    
    Node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }

    Node* prev = tail->back;
    
    Node* newNode = new Node(val, tail, prev);
    
    // Join the new node into the doubly linked list
    prev->next = newNode;
    tail->back = newNode;
    
    return head;
}

Node* insertBeforeKthElement(Node* head, int k, int val){
    
    if(k==1){
        // K = 1 means node has to be insert before the head
        return insertBeforeHead(head, val);
    }
    
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count ++;
        if(count == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    
    //join the new node in between prev and temp
    prev->next = newNode;
    temp->back = newNode;
    
    // Set newNode's pointers to prev and temp
    newNode->next = temp;
    newNode->back = prev;
    
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    vector<int> arr = {2,4 5,9,12};
    Node* head = convertarr2DLL(arr);
    print(head);
}

