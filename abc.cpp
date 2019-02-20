#include <bits/stdc++.h>

using namespace std;

struct SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode *next;
};

int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    vector<int> v;
    while(head){
        v.push_back(head->data);
        head = head->next;
    }
    return v[v.size()-positionFromTail];
}

int main()
{
    int T, N, pos;
    SinglyLinkedListNode *head, *q;
    std::cin>>T;
    while(T--){
        std::cin>>N;
        head = nullptr;
        for(int i=0;i<N;i++){
            std::cin>>pos;
            if(head == nullptr){
                head = new SinglyLinkedListNode{pos, nullptr};
                q = head;
            }else{
                q->next = new SinglyLinkedListNode{pos, nullptr};
                q = q->next;
            }
        }
        std::cin>>pos;
        std::cout<<getNode(head, pos)<<std::endl;
    }
    return 0;
}