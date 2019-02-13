#include <iostream>

struct Node {
    int data;
    Node *next, *prev;
};

Node *newnode(const int& val){
    Node *temp = new Node;
    temp->data = val;
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}

void pushFront(Node **head_ref, const int& val){
    Node *temp = newnode(val);
    temp->next = *head_ref;
    temp->prev = nullptr;
    if(*head_ref)
        (*head_ref)->prev = temp;
    *head_ref = temp;
}

void insertAfterNode(Node *prev_node, const int& val){
    if(!prev_node)
        return;
    Node *temp = newnode(val);
    temp->next = prev_node->next;
    temp->prev = prev_node;
    if(temp->next != nullptr)
        temp->next->prev = temp;
    prev_node->next = temp;
}

void appendEnd(Node **head_ref, const int& val){
    Node *temp = newnode(val);
    Node *q = *head_ref;
    if(!q){
        *head_ref = temp;
        return;
    }
    while(q->next)
        q = q->next;
    q->next = temp;
    temp->prev = q;
}

void insertBeforeNode(Node **head_ref, Node *next_node, const int& val){
    Node *temp = newnode(val);
    temp->next = next_node;
    temp->prev = next_node->prev;
    next_node->prev = temp;
    if(temp->prev != nullptr)
        temp->prev->next = temp;
    else
        *head_ref = temp;
}

void printList(Node* node)
{
    Node* last;
    std::cout<<"\nTraversal in forward direction \n";
    while (node){
        std::cout<<node->data<<' ';
        last = node;
        node = node->next;
    }
    std::cout<<"\nTraversal in reverse direction \n";
    while (last){
        std::cout<<last->data<<' ';
        last = last->prev;
    }
}

void deleteNode(Node **head_ref, Node *del){
    if(*head_ref == nullptr || del == nullptr)
        return;
    if(del == *head_ref)
        *head_ref = del->next;
    if(del->next != nullptr)
        del->next->prev = del->prev;
    if(del->prev != nullptr)
        del->prev->next = del->next;
    delete del;
    return;
}

int main(int argc, char *argv[]) {
    Node *head = nullptr;
    // appendEnd(&head, 6);
    // pushFront(&head, 7); 
    // pushFront(&head, 1); 
    // appendEnd(&head, 4); 
    // insertAfterNode(head->next, 8);
    // printList(head);
    pushFront(&head, 2);
    pushFront(&head, 4);
    pushFront(&head, 8);
    pushFront(&head, 10);
    printList(head);
    std::cout<<std::endl;
    deleteNode(&head, head);
    deleteNode(&head, head->next);
    deleteNode(&head, head->next);
    printList(head);
    std::cout<<std::endl;
    return 0;
}