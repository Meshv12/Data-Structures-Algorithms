Node* reverseDLL(Node* head)
{   
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* last = NULL;
    Node* curr = head;

    while(curr != NULL){
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;

        curr = curr->prev;
    }   

    return last->prev;
}