#include <iostream>
#include <vector>

struct node {
    short data;
    node *left, *right;
};

inline node* newnode(const short& val){
    return new node{val, nullptr, nullptr};
}

//Unbalanced BST to Balance BST
void inorder(std::vector<node*>& v, node* root){
    if(root){
        inorder(v, root->left);
        v.push_back(root);
        inorder(v, root->right);
    }
}

node* balanceUtil(std::vector<node*>& v, short start, short end){
    if(start > end)
        return nullptr;
    short mid = (start+end)>>1;
    node* temp = v[mid];
    temp->left = balanceUtil(v, start, mid-1);
    temp->right = balanceUtil(v, mid+1, end);
    return temp;
}

node* balancedTree(node* root){
    std::vector<node*> nodes;
    inorder(nodes, root);
    return balanceUtil(nodes, 0, nodes.size()-1);
}

//Create BST from array
node* insert(node* root, const short& val) {
    if(!root)
        return newnode(val);
    else{
        if(val <= root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
    }
}

void preorder(node* root){
    if(root){
        std::cout<<root->data<<' ';
        preorder(root->left);
        preorder(root->right);
    }
}

int main(int argc, char* argv[]) {
    short T, N, *arr;
    node* head;
    std::cin>>T;
    while(T--){
        std::cin>>N;
        head = nullptr;
        arr = new short[N];
        for(short i=0;i<N;i++){
            std::cin>>*(arr+i);
            head = insert(head, *(arr+i));
        }
        head = balancedTree(head);
        preorder(head);
        std::cout<<std::endl;
        delete[] arr;
    }
    return 0;
}