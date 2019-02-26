#include <iostream>

struct node{
    int data;
    node* left;
    node* right;
};

node* newNode(const int& val){
    node* temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp; 
}

node* findLCA(node* root, const int& num1, const int& num2){
    if(!root)
        return NULL;
    if(root->data == num1 || root->data == num2)
        return root;
    node* leftLCA = findLCA(root->left, num1, num2);
    node* rightLCA = findLCA(root->right, num1, num2);
    if(leftLCA && rightLCA)
        return root;
    return !leftLCA ? rightLCA : leftLCA;
}

node* lcaBST(node* root, const int& num1, const int& num2){
    if(!root)
        return NULL;
    if(root->data < num1 && root->data < num2)
        return lcaBST(root->right, num1, num2);
    if(root->data > num1 && root->data > num2)
        return lcaBST(root->left, num1, num2);
    return root;
}

int main(int argc, char* argv[]) {
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    std::cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data
            << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->data
            << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->data
            << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->data << '\n';

    root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    int n1 = 10, n2 = 14;
    node *t = lcaBST(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
    n1 = 14, n2 = 8;
    t = lcaBST(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
    n1 = 10, n2 = 22;
    t = lcaBST(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
    return 0;
}