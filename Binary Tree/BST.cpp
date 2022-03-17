#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
using namespace std;

int main()
{
    BST bst;
    bst.insert(6);
    bst.insert(3);
    bst.insert(5);
    bst.insert(1);
    bst.insert(9);
    bst.insert(10);
    bst.insert(11);
    bst.insert(12);
    bst.insert(7);
    bst.insert(8);

    cout<<"Maximum: "<<bst.Maximum()->data<<endl;
    cout<<"Minimum: "<<bst.Minimum()->data<<endl;

    cout<<"search 8: "<<bst.search(8)<<endl;
    cout<<"search 19: "<<bst.search(19)<<endl;
    cout<<endl<<"Inorder:"<<endl;
    inorder(bst.root);
    cout<<endl<<"Preorder:"<<endl;
    preorder(bst.root);
    cout<<endl<<"postorder:"<<endl;
    postorder(bst.root);
    cout<<endl<<"level order:"<<endl;
    levelorder(bst.root);
    
}