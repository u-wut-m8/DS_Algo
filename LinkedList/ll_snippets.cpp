#include <cstdlib>
#include <iostream>

struct Node {
    int data;
    Node *next;
};

inline Node* newNode(int val) {
    return new Node{val, NULL};
}


//LinkedList pailndrome or not
bool isPalindrome(Node *head)
{    Node *temp = head;
    int val1 = 0, val2 = 0, n = 1;
    while(temp){
        val1 += temp->data*n;
        val2 = val2*10 + temp->data;
        temp = temp->next;
        n *= 10;
    }
    if(val1 == val2)
        return true;
    return false;
}

//Insert in a sorted list
void sortedInsert(struct Node** head_ref, int data)
{
    // Code here
    Node *temp = new Node();
    temp->data = data;
    if(!head_ref)
        *head_ref = temp;
    Node *curr = *head_ref, *prev = NULL;
    while(curr != NULL){
        if(curr->data > data)
            break;
        prev = curr;
        curr = curr->next;
    }
    if(!prev){
        temp->next = *head_ref;
        *head_ref = temp;
    }else{
        prev->next = temp;
        temp->next = curr;
    }
}

//Mergesort LinkedList

void splitList(Node* source, Node** frontRef, Node** backRef)
{
    Node *p,*q,*t;
    p = q = source;
    while(q && q->next) {
        t=p;
        q=q->next->next;
        p=p->next;
    }
    if(q) {
        *backRef = p->next;
        p->next = NULL;
        *frontRef = source;
    } else {
        *backRef = t->next;
        t->next = NULL;
        *frontRef = source;
    }
}

Node* mergeList(Node* a, Node* b)
{
    if(!a)
        return b;
    if(!b)
        return a;
    if(a->data>b->data) {
        b->next = mergeList(a,b->next);
        return b;
    }
    else {
        a->next = mergeList(a->next,b);
        return a;
    }
}

void mergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a, *b;
    if ((head == NULL) || (head->next == NULL))
       return;
    splitList(head, &a, &b); 
    mergeSort(&a);
    mergeSort(&b);
    *headRef = mergeList(a, b);
}

int main(int argc, char* argv[]) {
    Node **arr = NULL;
    *arr = newNode(5);
    Node *potato = *arr;
    int c = 5;
    while(c--){
        potato->next = newNode(c);
        potato = potato->next;
    }
    mergeSort(arr);
    Node *temp = *arr;
    while(temp){
        std::cout<<temp->data<<' ';
        temp = temp->next;
    }
    std::cout<<std::endl;
    delete[] arr;
    return 0;
}