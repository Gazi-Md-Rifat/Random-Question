#include <iostream>
using namespace std;


class Node {
public:
    int val;
    Node *next;

    Node(int x){
        val = x;
        next = NULL;
    }

};


Node *makeLikedList(Node *head, int val){
    if (head == NULL){
       return new Node(val);
    }
    head ->next = makeLikedList(head->next, val);
    return head;
}

void deleteDuplicate(Node *head, int val){
    if (!head){
        return;
    }
    if (head->next && head->next->val == val){
        head->next = head->next->next;
        deleteDuplicate(head, val);
    }
    deleteDuplicate(head->next, val);
    return;
}


int main(){

    Node *head = NULL;
    int n1, n2;
    while(1){
        cin >> n1;
        if (n1 == -1){
            break;
        }
       head = makeLikedList(head, n1);
    }

    Node *root = head;
    while(head){
        deleteDuplicate(head, head->val);
        head = head->next;
    }

    // cout << endl << endl << endl;

    while(root){
        cout << root->val << " ";
        root = root->next;
    }

    return 0;
}