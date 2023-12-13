#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1){
        data1 = data;
        next1 = next;
    }
    public:
    Node(int data1){
        data1 = data;
        next = nullptr;
    }
};

Node* convertarr2LL(vector<int>& arr){
    Node* head = new Node(arr[0]);         // create head
    Node* mover = head;                    // pointing to head
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);     // creating new node for every element
        mover->next = temp;                // connect prev element to current
        mover = mover->next;               // moving mover to next ptr
    }
    return head;
}

int lengthOfLL(Node* head){
    Node* temp = head;
    int cnt = 0;

    // Traverse in LL
    while(temp != NULL){
        temp = temp -> next;
        cnt++;
    }
    return cnt; 
}

Node* removesHead(Node* head) {
    // Check if the linked list is empty
    if (head == NULL)
        return head;

    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteTail(Node* head) {
    if (head == NULL || head->next == NULL)     // only 0 or 1 element
        return NULL;

    Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = nullptr;
    return head;
}

Node* deleteKthNode(Node* head, int k) {
    if (head == NULL)
        return head;

    // If k is 1, delete the first node
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Traverse the list to find the k-th node
    Node* temp = head;
    Node* prev = NULL;
    int cnt = 0;

    while (temp != NULL) {
        cnt++;
        if (cnt == k) {
            // Adjust the pointers to skip the k-th node
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        // Move to the next node
        prev = temp;
        temp = temp->next;
    }

    return head;
}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

Node* insertTail(Node* head, int val) {
    if (head == NULL){
        Node* temp = new Node(val);
        return temp;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    Node* newNode = new Node(val);
    temp->next = newNode;

    return head;
}

Node* insertAtK(Node* head, int val, int k) {
    // If the linked list is empty and k is 1, insert the new node as the head
    if (head == NULL) {
        if (k == 1)
            return new Node(val);
        else
            return head;
    }

    // If k is 1, insert the new node at the beginning of the linked list
    if (k == 1)
        return new Node(val, head);

    int cnt = 0;
    Node* temp = head;

    // Traverse the linked list to find the node at position k-1
    while (temp != NULL) {
        cnt++;
        if (cnt == k - 1) {
            // Insert the new node after the node at position k-1
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

int main(){
    vector<int> arr = {2,4,7,9,12};
    Node* head = convertarr2LL(arr);

    cout << "Number of nodes in LL are " << lengthOfLL(head) << "\n"
}

