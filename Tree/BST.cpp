#include <iostream>

struct node {
    int data;
    node *left, *right;
};

node* newnode(int val){
    node* temp = new node;
    temp->data = val;
    temp->left = temp->right = nullptr;
    return temp;
}

void preorder(node* root){
    if(!root)
        return;
    std::cout<<root->data<<' ';
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(!root)
        return;
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->data<<' ';
}

void inorder(node* root){
    if(!root)
        return;
    inorder(root->left);
    std::cout<<root->data<<' ';
    inorder(root->right);
}

node* insert(node* root, int val){
    if(!root)
        return newnode(val);
    if(val <= root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

node* search(node* root, int val){
    if(root == nullptr)
        return nullptr;
    else if(root->data == val)
        return root;
    else if(val <= root->data)
        search(root->left, val);
    else
        search(root->right, val);
}

int main(int argc, char* argv[]) {
    int N, temp;
    node *root = nullptr, *q;
    std::cin>>N;
    for(int i=0;i<N;i++){
        std::cin>>temp;
        root = insert(root, temp);
    }
    std::cin>>temp;
    q = search(root, temp);
    preorder(q);
    return 0;
}