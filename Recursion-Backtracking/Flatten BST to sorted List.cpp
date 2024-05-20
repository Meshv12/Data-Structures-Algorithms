#include <bits/stdc++.h>
using namespace std;

Node *flattenBST(Node *root)
{
    if (!root)
    {
        return NULL;
    }

    Node *head = flattenBST(root->left);
    root->left = NULL;
    root->right = flattenBST(root->right);

    if (head)
    {
        Node *temp = head;
        while (temp->right)
        {
            temp = temp->right;
        }
        temp->right = root;
    }
    else
    {
        // If head is NULL, root becomes the head
        head = root;
    }

    return head;
}
