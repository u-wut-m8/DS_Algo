#include <iostream>
<<<<<<< HEAD
#include <vector>

struct node {
    int data;
    node *left, *right;
};

inline node* newnode(const int& val){
    return new node{val, nullptr, nullptr};
}

node* insert(node* root, const int& val) {
    if(!root)
        return newnode(val);
    else{
        if(val <= root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
    }
}

node* find(node* root, int& temp){
  if(!root || root->data == temp)
    return nullptr;
  else{
    if(temp < root->data)
      root->left = find(root->left, temp);
    else
      root->right = find(root->right, temp);
    return root;
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
    int T, N, Q, temp, *arr;
    node* head, *q;
    std::cin>>T;
    while(T--){
        std::cin>>N>>Q;
        head = nullptr;
        arr = new int[N];
        for(int i=0;i<N;i++){
            std::cin>>arr[i];
            head = insert(head, arr[i]);
        }
        while(Q--){
          std::cin>>temp;
          q = nullptr;
          for(int i=0;i<N;i++){
            q = insert(q, arr[i]);
          }
          q = find(q, temp);
          if(!q)
            std::cout<<"Empty";
          else
            preorder(q);
            std::cout<<std::endl;
        }
        delete[] arr;
    }
=======

int main(int argc, char* argv[]) {
>>>>>>> 1d45762d4063f82b4d847b9617634c952a263906
    return 0;
}