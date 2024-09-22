#include<iostream>
using namespace std;

template<typename T>

class Tree{
    public:

    T data;
    Tree *left, *right;

    Tree(T val){
        data = val;
        left = right = NULL;
    }

    void preorder(Tree* root){  //as we passing each as root, means root->left or root->right accept as root
        // NLR
        if (root == NULL)       //means have no child so return back
        {
            return;
        }
        
        cout << root->data << " ";      //N
        preorder(root->left);           //L
        preorder(root->right);          //R
    }

    void inorder(Tree* root){  //as we passing each as root, means root->left or root->right accept as root
        // LNR
        if (root == NULL)       //means have no child so return back
        {
            return;
        }

        inorder(root->left);           //L
        cout << root->data << " ";      //N
        inorder(root->right);          //R
    }

    void postorder(Tree* root){
        //LRN
        if(root == NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main(){
// //if does not make any template then:
//     Tree *root = new Tree('1');
//     root->left = new Tree('2');
//     root->right = new Tree('3');
//     root->left->left = new Tree('a');
//     root->left->right = new Tree('b');
//     root->right->left = new Tree('c');
//     root->right->right = new Tree('d');

//     root->preorder(root);

    // Dynamically create the tree
    Tree<char>* root = new Tree<char>('1'); //root is pointer points to object Tree<char> created dynamically.
    root->left = new Tree<char>('2');       //root->left also a pointer points to object Tree<char> created dynamically.
    root->right = new Tree<char>('3');      // & so on

    root->left->left = new Tree<char>('4');
    root->left->right = new Tree<char>('5');

    root->right->left = new Tree<char>('6');
    root->right->right = new Tree<char>('7');

    cout<< "Preorder Traversing:\t";
    root->preorder(root);
    cout<< "\nInorder Traversing:\t";
    root->inorder(root);
    cout<< "\nPostorder Traversing:\t";
    root->postorder(root);
//OR

    // // Statically create the tree                LAMBI
    // Tree<char> root('1');
    // Tree<char> leftChild('2');
    // Tree<char> rightChild('3');
    // Tree<char> leftLeftChild('a');
    // Tree<char> leftRightChild('b');
    // Tree<char> rightLeftChild('y');
    // Tree<char> rightRightChild('z');

    // // Build the tree structure by linking nodes
    // root.left = &leftChild;
    // root.right = &rightChild;

    // leftChild.left = &leftLeftChild;
    // leftChild.right = &leftRightChild;

    // rightChild.left = &rightLeftChild;
    // rightChild.right = &rightRightChild;

    // root.preorder(&root);
}
// g++ -o tree D:\sem4\dsa\code\tree.cpp
// g++ -o tree D:\SEMESTER4\PM_Sem4\sem4\dsa\code\tree.cpp






// //  Construct a TREE from POSTFIX expression
// //Totally Same logic while duing Pre & Post evaluation. 
// // Difference:  1)Start loop from opposite of OPERATORS.    2)Pop first in op2 in Post  but first pop goes in op1 in Pre
// //Same logic to construct TREE from PREFIIX, just 2 changes come
// #include<iostream>
// #include<stack>
// using namespace std;
// //Logic: push operand in stack, if operator comes then pop 2 operands from stack assign 1st one as Right child. Then push whole node
// // template<typename T>
// class Node{
//     public:
//         char data;
//         // Node* left,right;        WRONG: left is a pointer point to Node, but right is an object of Node not a pointer
//         Node* left, *right;
 
//         Node(char value){
//             data = value;
//             left = right = NULL;
//         }
// };

// int isOperator(char c){
//     switch (c)
//     {
//     case '+': case '-': case '*': case '/': case '^': case '%': return 1; 
//     default: return 0; // return 0 for operands
//     }
// }

// void exp_to_tree(string postfix, int size, Node **root){
//     stack<Node*> st;            //stack<char> st;          WRONG ku key hum hum char nhi bulkey hum Node push ya pop kr waa rahe h
           
//     for (int i = 0; i < size; i++)          //POSTFIX
//     // for (int i = size-1; i>=0; i--)    //PREFIX
//     {
//         Node* temp = new Node(postfix[i]); 
//         if(isOperator(postfix[i]) == 0){    //not a operator
//             st.push(temp);
//         }
//         else{
//             //For prefix order will change. first left then right
//             temp->right = st.top();
//             st.pop();
//             temp->left = st.top();
//             st.pop();
//             st.push(temp);
//         }
//     }
//     *root = st.top();
//     st.pop();
//     // cout << "The tree is:\n" << (*root)->data <<endl;
// }

// void inorder(Node* root){
//     if(root == NULL){
//         return;
//     }
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }

// int main(){
//     string postfix = "AB+CD-*";
//     int size = postfix.length();
//     Node* root = NULL;
//     exp_to_tree(postfix, size, &root);
//     inorder(root);
// }
// // g++ -o tree D:\sem4\dsa\code\tree.cpp
// // g++ -o tree D:\SEMESTER4\PM_Sem4\sem4\dsa\code\tree.cpp