#include <iostream>
#include <utility>

struct node {
    int data;
    node *left, *right;
};

inline node* newNode(const int& val){
    return new node{val, nullptr, nullptr};
}

std::pair<int, int> maxSum(node* root){
    if(!root)
        return std::make_pair(0, 0);
    std::pair<int, int> l = maxSum(root->left);
    std::pair<int, int> r = maxSum(root->right);
    int rootToLeaf = root->data + l.first > r.first ? l.first : r.first;
    int maxSum = root->data + l.first + r.first;
    maxSum = maxSum > l.second > r.second ? l.second : r.second ? maxSum : l.second > r.second ? l.second : r.second;
    return std::make_pair(rootToLeaf, maxSum);
}

inline int maxPathSum(node *root) {
    return maxSum(root).second;
}

void insert(node *root, int a1,int a2, char lr){
	if(root==NULL)
		return;
	if(root->data == a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
					break;
			case 'R':root->right=newNode(a2);
					break;
		}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    std::cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
	int t;
	std::cin>>t;
	while(t--){
		int n;
		std::cin>>n;
		node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			std::cin>>a1>>a2>>lr;
			if(root==NULL){
				root=newNode(a1);
				switch(lr){
					case 'L':root->left=newNode(a2);
							break;
					case 'R':root->right=newNode(a2);
							break;
				}
			}
			else
				insert(root,a1,a2,lr);
		}
		std::cout<<maxPathSum(root)<<std::endl;		
	}
}