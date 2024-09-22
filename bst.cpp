// insertion      O(logn)         O(n)
// search         O(logn)         O(n)
// deletion

// later INORDER predecessor & successor, kisi bhi number ka jo hum pass kr waae
#include <iostream>
using namespace std;

class BST
{
public:
    int data;
    BST *left, *right;

    BST(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// INSERTION (bst mein element hamesha last mein hi add hote h, in b.w kisi ko replace kr key nhi ho skht)
BST *make_bst(BST *root, int val)
{
    if (root == NULL)
    {
        return new BST(val); // adding element
    }
    else if (val < root->data)
    {
        root->left = make_bst(root->left, val);
    }
    else
    {
        root->right = make_bst(root->right, val);
    }
    return root;
}

void inorder(BST *root)
{ // here root means either root->left or root->right
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << ", ";
    inorder(root->right);
}
// wrong approach:
//  void largest(BST *root){   //error: void value not ignored as it ought to be
//      if(root == NULL){
//  Dusra masla ye base cond ka h, jb root null ho gaya tou root->data kha sey aaega, undefined behvaiour isi wajah sey ye method bhi kuch print nhi karega
//          cout << "Largest element in the BST is: "<< root->data << endl;
//          return;
//      }
//      root->right = largest(root->right);     //due to this line as largest func is of void type which is not returning anything & i am here assigning.
//  }

BST* largest(BST *root)
{ // traversing to right most child
    if (root->right == NULL)
    { // root = root->right b/c of recursive & root->right = root->right->right
        // cout << "\nLargest element in the BST is: " << root->data << endl;
        return root;
    }
    largest(root->right);
}

BST* smallest(BST *root)
{ // traversing to left most child
    if (root->left == NULL)
    { // root = root->left b/c of recursive & root->left = root->left->left
        // cout << "Smallest element in the BST is: " << root->data << endl;
        return root;
    }
    smallest(root->left);
}

// iterative approach, T.C= logn     S.C=constant                SEARCH
bool element_exist(BST *root, int no)
{
    BST *temp = root;
    while (temp != NULL)
    {
        if (temp->data == no)
        {
            cout << "Element found: " << endl;
            return true;
        }
        else if (temp->data < no)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return false;
}

// //recursive approach, T.C= logn     S.C=logn                         SEARCH
// bool element_exist(BST *root, int no)
// {
//     if (root == NULL)
//     {
//         return false;
//     }
//     if (no == root->data)
//     {
//         cout<< "Element found: " <<endl;
//         return true;
//     }
//     else if (no > root->data)
//     {
//         return element_exist(root->right, no);
//     }
//     else
//     {
//         return element_exist(root->left, no);
//     }
// }

BST *delete_node(BST *root, int no)
{
    if (root == NULL)
    {
        // return false;
        cout << "Element not found, Can't delete" << endl;
        return root;
    }
    if (no == root->data)
    {
        // LEAF node case
        if (root->left == NULL && root->right == NULL)
        {
            cout << "LEAF node case:" << endl;
            delete (root);
            cout << "Element successfully deleted" << endl;
            return NULL;
        }
        // ONE child node case
        else if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
        {
            cout << "Single child node case:" << endl;
            if (root->left == NULL && root->right != NULL)
            {
                BST *temp = root->right;
                delete (root);
                cout << "Element successfully deleted" << endl;
                return temp;
            }
            else
            {
                BST *temp = root->left;
                delete (root);
                cout << "Element successfully deleted" << endl;
                return temp;
            }
        }
        // TWO child node case:
        else
        {
            cout << "TWO child node case:" << endl;
            int choice;
            cout << "Enter 1 to insert L_S_T element or 2 to insert R_S_T element:" << endl;
            cin >> choice;
            int value;
            if (choice == 1)
            {
                BST* temp = largest(root->left);
                root->data = temp->data;
                cout << "Element successfully deleted" << endl;
                root->left = delete_node(root->left,temp->data);
            }
            else if(choice == 2)
            {
                BST* temp = smallest(root->right);
                root->data = temp->data;
                cout << "Element successfully deleted" << endl;
                root->right = delete_node(root->right,temp->data);
            }
            else
            {
                cout << "Invalid selection " << endl;
            }
        }
    }
    else if (no > root->data)
    {
        root->right = delete_node(root->right, no);
    }
    else
    {
        root->left =  delete_node(root->left, no);
    }
    return root;
}

int main()
{
    // Aese Directly call kr skhtey h '->' ye lagane ki zaroorat nhi , ye masla is liye aata thaa ku key mein CLASS mein hi methods daal deta hu or phir scope ka masla aa jaata h
    //  int arr[] = {5, 1, 3, 4, 2, 7};
    int arr[] = {8, 3, 1, 6, 4, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    BST *root = NULL;
    for (int i = 0; i < size; i++)
    {
        root = make_bst(root, arr[i]);
    }
    // alag sey, no add kr waa raha hu.
    make_bst(root, 5);

    inorder(root);
    // largest(root);
    // smallest(root);

    int ele_tocheck;
    cout << "\nEnter element u want to search:" << endl;
    cin >> ele_tocheck;
    bool found1 = element_exist(root, ele_tocheck);
    if (found1 == true)
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }

    int ele_todel;
    cout << "\nEnter element u want to delete:" << endl;
    cin >> ele_todel;
    // delete_node(root, ele_todel);    Wrong , neeche wale ko comment kro phir run kro kuch display nhi hoga ku key Jo updated root delete_node return kr raha h wo mein accept/assign hi nhi kr wa rha thaa
    root = delete_node(root, ele_todel);

    cout << "\nEnter element u want to search:" << endl;
    cin >> ele_tocheck;
    bool found2 = element_exist(root, ele_tocheck);
    if (found2 == true)
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }

    inorder(root);
    // OR
    //  root = make_bst(root, 5);
    //  make_bst(root, 1);
    //  make_bst(root, 3);
    //  make_bst(root, 4);
    //  make_bst(root, 2);
    //  make_bst(root, 7);
    //  inorder(root);
    //  largest(root);
    //  smallest(root);
}
// g++ -o bst D:\SEMESTER4\PM_Sem4\sem4\dsa\code\bst.cpp