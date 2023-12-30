// First Odd elements then Even elements

Node *oddEvenList(Node *head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *evenhead = even;

    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenhead;

    return head;
}