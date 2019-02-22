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

int maxDepth(node* root, int &m){
    if(!root)
        return 0;
    int lDepth = maxDepth(root->left, m);
    int rDepth = maxDepth(root->right, m);
    if(lDepth + rDepth + 1 > m)         //diameter of binary tree             
        m = lDepth + rDepth + 1;        
    if(lDepth > rDepth)
        return lDepth+1;
    else
        return rDepth+1;
}

void setLeft(node* root, int val){
    if(!root->left)
        root->left = newnode(val);
    else{
        node* temp = newnode(val);
        temp->left = root->left;
        root->left = temp;
    }
}

void setRight(node* root, int val){
    if(!root->right)
        root->right = newnode(val);
    else{
        node* temp = newnode(val);
        temp->right = root->right;
        root->right = temp;
    }
}

int main(int argc, char* argv[]){
    int T, X, iter, m;
    node* root = nullptr, *temp;
    std::string s;
    std::cin>>T>>X;
    root = newnode(X);
    for(int i=0;i<T-1;i++){
        std::cin>>s>>X;
        temp = root;
        iter = 0;
        while(temp and iter < s.size()){
            if(s[iter] == 'L'){
                if(!temp->left)
                    temp->left = newnode(-1);
                temp = temp->left;
            }else{
                if(!temp->right)
                    temp->right = newnode(-1);
                temp = temp->right;
            }
            iter++;
        }
        temp->data = X;
    }
    m = -1;
    maxDepth(root, m);
    std::cout<<m<<std::endl;
    return 0;
}