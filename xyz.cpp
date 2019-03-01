#include <iostream>
#include <utility>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void inorder(Node *root, vector<int>& v) {
    if (root == NULL)
       return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

bool isPresent(std::vector<int> v){
  int l, r;
  for(int i=0;i<v.size();i++){
    l = i+1;
    r = v.size()-1;
    while(l < r){
      if(v[i]+v[r]+v[l] == 0)
        return true;
      else if(v[i]+v[r]+v[l] > 0)
        r--;
      else
        l++;
    }
  }
  return false;
}

bool isTripletePresent(Node* root){
  std::vector<int> v;
  inorder(root, v);
  return isPresent(v);
}

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     printf(" ");
     printf(" ");
  }
  return 0;
}