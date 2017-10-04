#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct Tree{
    struct Tree *left;
    int data;
    struct Tree *right;
}Tree;
typedef Tree *tree;
tree t= new Tree;

tree getTree(int val);

int main(void){
    tree t= new Tree;
    t->data = 3;
    insert_data(t,5);
    insert_data(t,9);
    insert_data(t,2);
    insert_data(t,7);
    cout<<t->data;
}
tree getTree(int val){
    tree temp = new Tree;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
