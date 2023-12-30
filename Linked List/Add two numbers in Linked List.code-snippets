Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node* dummyhead = new Node(-1);
    Node* curr = dummyhead;
    Node* temp1 = num1;
    Node* temp2 = num2;
    int carry = 0;

    while(temp1 != NULL || temp2 != NULL){
        int sum = carry;
        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;

        Node* x = new Node(sum%10);
        carry = sum/10;

        curr->next = x;
        curr = x;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }

    if(carry != 0){
        Node* newnode = new Node(carry);
        curr->next = newnode;
    }

    return dummyhead->next;
}