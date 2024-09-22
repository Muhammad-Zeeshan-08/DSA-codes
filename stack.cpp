//Stack Implementation through Arrays
#include<iostream>
using namespace std;

class Stack{

    public:
    // properties
    char *arr;
    int length;
    int top;

    //constructor
    Stack(int size){
        length = size;
        arr = new char[size];
        top = -1;
    }

    //behaviour
    void push(int data){
        //first check boundary, means is it overflow or not
        if(length - top > 1){     //e.g;  if length is 5 then top will max 4(index) so top is always less than .
            cout<< "Push is possible.\n";
            top++;  //first inc top b/c it is -1 by default
            arr[top] = data; 
        }
        else{
            cout<< "Push is NOT possible, OVERFLOW state.\n";
        }

    }

    int pop(){
        //first check boundary, means is it underflow or not
        if(top>-1){ //top==-1 ; WRONG b/c top value is not always -1 , it can be any
            int value = arr[top];
            // cout<< "Pop done.\n";
            top--;
            return value;
        }
        else{
            cout<< "Pop is NOT possible, UNDERFLOW state.\n";
            return -1;
        }
    }

    int peek(){
        if(top>=0 && top<length){
            // cout << "The value at the top of Stack is: " << arr[top] << endl;
            return arr[top];
        }
        else{
            // cout<< "Does not exist.\n";
            return -1;
        }
    }

    // void isEmpty(){
    //     if(top == -1){
    //         cout << "Stack is Empty.\n";
    //     }
    //     else{
    //         cout << "Stack is not Empty.\n";
    //     }
    // }
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    void display(){
        if(top == -1){
            cout << "Nothing to display as Stack is Empty.\n";
        }
        else{
            int i = top;
            while(i>-1){
                cout << arr[i] << ", ";
                i--;
            }
            cout<< endl;
        }
    }
};


// // YE SB WAHA LIKHA JAAEGA JAHA ISKO CALL KR RAHE HONGE.
// int main(){
//     int size;
//     cout << "Enter size of an array:\n";
//     cin >> size;
//     Stack st(size); //contructor will call

//     cout << "\nSize of the Stack is: " << st.length << endl;
//     st.isEmpty();
//     st.peek();
//     st.push(2);
//     st.push(4);
//     st.push(6);
//     st.push(8);
//     st.push(0);
//     cout << "Pushing done.\n\n";

//     st.isEmpty();
//     st.peek();

//     st.pop();
//     st.pop();
//     cout<< "\nAfter poping out 2 values.\n";
//     st.peek();
//     st.isEmpty();

//     st.pop();
//     int pop = st.pop();
//     cout<< "Last pop which i do, here i only store return value out of any other call & its value is: " << pop << endl;
//     cout<< "\nAfter poping out 2 more values.\n\n";
//     st.peek();
//     st.isEmpty();
// }
// g++ -o stack D:\sem4\dsa\code\stack.cpp
// g++ -o stack D:\SEMESTER4\PM_Sem4\sem4\dsa\code\stack.cpp





// //Stack Implementation through Linked List
// #include<iostream>
// using namespace std;

// class Node{
//     public: 
//     int data;
//     Node* next;
//     int top;
//     int size;

//     Node(int val){
//         data = val;
//         next = NULL;
//         top = -1;
//         size = top + 1;
//     }

//     void push(Node *&head, int val){
//         // Node tou sirf 1 baar add ho rahi h tou sirf 1 baar increment
//         Node* newnode = new Node(val);
//         top++;
//         size++;

//         if(head == NULL){
//             head = newnode;
//         }
//         else{
//             Node* temp = head;
//             while(temp->next != NULL){
//                 // top++;           Galat h ku key hum traverse kr rahe h naa kr node ki addition
//                 temp = temp->next;
//             }
//             temp->next = newnode;
//         }
//     }

//     void pop(Node *&head){
//         if (head == NULL || size == 0 || top == -1) // no node
//         {
//             cout << "Due to UNDERFLOW state, u can't pop out any more element";
//             return;
//         }
//         else if (head->next == NULL || size == 1 || top == 0) //single node
//         {
//             Node *temp = head;
//             head = head->next;
//             delete temp;
//             top--;
//             size--;
//             return;
//         }
//         else
//         {
//             // Node* phichla=head
//             Node *phichla = head;
//             // for e.g; deleting from last pos means if top=5 then i will link i=4->next  with  i=5->next
//             int i = 1;
//             while (i != size - 1)        //if actual size is 5 then last node will be 4th
//             {
//                 phichla = phichla->next;
//                 i++;
//             }
//             top--;
//             size--;
//             phichla->next = NULL;
//             return;
//         }
//         return;
//     }

//     void peek(Node* head){
//         int i = 1;
//         Node* temp = head;
//         while(i<size){
//             temp = temp->next;
//             i++;
//         }
//         cout << "The top of the Node is: " << temp->data <<endl;
//     }

//     void empty(Node* head){
//         if (head == NULL || size == 0 || top == -1) // no node
//         {
//             cout << "Stack is Empty\n";
//             return;
//         }
//         else{
//             cout << "Stack is not Empty\n";
//         }
//     }

//     void display(Node* head){
//         Node* temp = head;
//         while(temp != NULL){
//             cout << temp->data << ", ";
//             temp = temp->next;
//         }
//         cout<< endl;
//     }
// };

// int main(){
//     Node* head = NULL;
//     Node node(0);

//     node.empty(head);
//     node.push(head , 0);
//     node.push(head , 2);
//     node.push(head , 4);
//     node.push(head , 6);
//     node.push(head , 8);
//     node.peek(head);
//     node.empty(head);
//     node.display(head);
//     cout << "Size of the node: " << node.size << endl << endl;

//     node.pop(head);
//     node.peek(head);
//     node.empty(head);
//     node.pop(head);
//     node.pop(head);
//     node.peek(head);
//     node.empty(head);
//     node.display(head);
//     cout << "Size of the node: " << node.size << endl;
// }
// g++ -o stack D:\sem4\dsa\code\stack.cpp
// g++ -o stack D:\SEMESTER4\PM_Sem4\sem4\dsa\code\stack.cpp





// //STACK standardly or directly through build in functions
// #include<iostream>
// #include<stack>
// using namespace std;

// int main(){
//     // Creation of stack;
//     stack<int> a;
//     if (a.empty())
//     {
//         cout << "\nStack is Empty\n";
//     }
//     else{
//         cout << "\nStack is not Empty\n";
//     }
    
//     a.push(2);
//     a.push(4);
//     a.push(6);
//     a.push(8);
//     cout<< "Size of Stack: " << a.size() << endl;
//     cout<< "Top  of Stack: " << a.top() << endl;

//     a.pop();
//     a.pop();
//     a.pop();
//     cout<< "Size of Stack: " << a.size() << endl;
//     cout<< "Top  of Stack: " << a.top() << endl;

//     if (a.empty())
//     {
//         cout << "Stack is Empty\n";
//     }
//     else{
//         cout << "Stack is not Empty\n";
//     }
// }





// // Single TEMPLATE for different Data Types
//     //Use template <typename T> (or template <class T>) before the class or function definition.
//     //Instantiation:    classname<d.t>  name(construc para)         e.g;    Stack<int>  st(5);
// #include <iostream>
// using namespace std;

// template <typename T>
// class Stack {
// public:
//     // properties
//     T *arr;     // Use a generic type T instead of char
//     int length;
//     int top;

//     // constructor
//     Stack(int size) {
//         length = size;
//         arr = new T[size];  // Allocate memory for T
//         top = -1;
//     }

//     // destructor
//     ~Stack() {
//         delete[] arr; // Clean up the allocated memory
//     }

//     // behaviour
//     void push(T data) {
//         if (length - top > 1) {
//             top++;
//             arr[top] = data;
//         } else {
//             cout << "Push is NOT possible, OVERFLOW state.\n";
//         }
//     }

//     T pop() {
//         if (top > -1) {
//             T value = arr[top];
//             top--;
//             return value;
//         } else {
//             cout << "Pop is NOT possible, UNDERFLOW state.\n";
//             return T(); // Return default-constructed T
//         }
//     }

//     T peek() {
//         if (top >= 0 && top < length) {
//             return arr[top];
//         } else {
//             return T(); // Return default-constructed T
//         }
//     }

//     bool isEmpty() {
//         return top == -1;
//     }

//     void display() {
//         if (top == -1) {
//             cout << "Nothing to display as Stack is Empty.\n";
//         } else {
//             int i = top;
//             while (i > -1) {
//                 cout << arr[i] << ", ";
//                 i--;
//             }
//             cout << endl;
//         }
//     }
// };

// int main() {
//     // Example usage with integers
//     int size;
//     cout << "Enter size of an array: ";
//     cin >> size;
//     Stack<int> intStack(size); // Create stack for int

//     cout << "\nSize of the Stack is: " << intStack.length << endl << endl;
//     intStack.push(12);
//     intStack.push(24);
//     intStack.push(36);
//     intStack.push(48);
//     intStack.push(50);
//     intStack.display();
//     cout << "Pushing done.\n";

//     intStack.pop();
//     intStack.pop();
//     cout << "After popping out 2 values.\n";
//     intStack.display();

//     // Example usage with characters
//     cout<<endl;
//     Stack<char> charStack(size); // Create stack for char
//     charStack.push('a');
//     charStack.push('b');
//     charStack.push('c');
//     charStack.display();
//     cout << "Pushing done.\n";

//     charStack.pop();
//     charStack.pop();
//     cout << "After popping out 2 values.\n";
//     charStack.display();

//     return 0;
// }
// g++ -o stack D:\sem4\dsa\code\stack.cpp
// g++ -o stack D:\SEMESTER4\PM_Sem4\sem4\dsa\code\stack.cpp




// ````````````````````````````````````````````````````PRACTICE````````````````````````````````````````````````
        // //INFIX TO POSTFIX conversion
// #include <iostream>
// #include "stack.cpp"
// using namespace std;

// int preced(char c)
// {
//     switch (c)
//     {
//         case '+': case '-': return 1;
//         case '*': case '/': case '%': return 2;
//         case '^': return 3;
//         default: return 0;  // Non-operator characters
//     }
// }

// void infixTopostfix(string infix, string postfix, int str_len)
// {
//     Stack st(str_len); // as my stack constructor took 1 para which is size
//     for (int i = 0; i < str_len; i++)
//     {
//         // if(preced(infix[i]) == 0 ){
//         if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
//         {
//             postfix += infix[i];
//         }
//         else if (infix[i] == '(')
//         {
//             st.push(infix[i]);
//         }
//         else if (infix[i] == ')')
//         {
//             while (st.peek() != '(')
//             {
//                 // infix[i] != '('    Wrong condition, hum ney stack mein check krna h naa key infix mein
//                 postfix += st.pop(); // mera pop aesa h jo value return bhi karega or decrement bhi karega
//             }
//             // openeing bracket ko tou hum ney append nhi krna hota bus isko igonre maartey h tou neechey usi ki coding h
//             int o_bracket = st.pop();
//         }
//         else
//         {
//             if (preced(infix[i]) > preced(st.peek()))
//             {
//                 st.push(infix[i]);
//             }
//             else
// //YE CONDITION DEKHNA BOHAT BOHAT IMPORTANT H:          !st.isEmpty()
// //to check if the stack is empty or not, then we can do pop only
//             {
//                 if (infix[i] == '^')
//                 {
//                     while (!st.isEmpty() && preced(infix[i]) < preced(st.peek()))
//                     {
//                         postfix += st.pop();
//                     }
//                 }
//                 else
//                 {
//                     while (!st.isEmpty() && preced(infix[i]) <= preced(st.peek()))
//                     {
//                         postfix += st.pop();
//                     }
//                 }
//                 st.push(infix[i]);
//             }
//         }
//     }
//     // ab jb key mein ney poori infix exp ko access krlia tou mumkin h stack mein kuch operator rehtey ho tou bus unko la raha hu
//     while (!st.isEmpty())
//     {
//         postfix += st.pop();
//     }
//     cout << "Postfix expression is: " << postfix << endl;
// }

// int main()
// {
//     string infix = "a+b*c^2";
//    //"(a-b/c)*(a/k-l)"    "a+b*c"    "a+b"     "a*b+c"     "a+b-c+d"
//    //"a+b*c^2"     SIrf iska jawab sahi nhi dey raha, abc^*+2  dey raha h  jb key abc2^*+   aaana chahiye
//     string postfix = "";
//     int length = infix.length();

//     cout << "Infix expression is: " << infix << endl;
//     cout << "Total length of Infix string is: " << length << endl;
//     infixTopostfix(infix, postfix, length);
// }
// g++ -o stack D:\sem4\dsa\code\stack.cpp
// g++ -o stack D:\SEMESTER4\PM_Sem4\sem4\dsa\code\stack.cpp




//                                              PREFIX VS POSTFIX (main pt to remember)
// 1)In prefix we start loop from R.H.S & In postfix we start loop from L.H.S.
// in short start from oppsite side of operator
// 2)Pre mein hum R.H.S sey move krtey h tou jo pheley char aata h wo basically baad ka hota h or Stack mein neechey hota h, isi liye hum op1(oplower) mein pheley pop kr waate h or op2(ophigher) mein baad wale ko hi
// Jb key Post mein hum L.H.S sey move krtey h tou jo pheley char aata h wo basically pheley wala hi hota h or Stack mein neechey hota h, isi liye hum op2(ophigher) mein pheley pop kr waate h or op1(oplower) mein baad wale ko hi


//Prefix Evalution      Yanni prefix di hui h or hum calculation
// #include<iostream>
// #include<stack>
// #include<math.h> // as i am also dealing with power, so calling power method from this file
// using namespace std;
// //not using own stack b/c i only make stack of int, but i will need different D.T stacks

// int prefix_evaluation(string s){
//     stack<int> st;
//      //start from opposite side of operator, means the operators came at L.H.S, so here starts from R.H.S
//     for(int i = s.length()-1 ; i>=0 ; i--){  //checking if it is operand or not
//         if(s[i]>='0' && s[i] <='9'){  //can't apply || this condition
//             st.push(s[i]-'0');
//         // st[i]  nhi likh skhte, hmein as an INT push krna. tou adjustment ky lie,like in assembly
//         }
//         else{    // if operator then popping out 2 values & apply that operation which comes & pushing its result
//             int operand1 = st.top(); //ye basically string mein pheley wala h
//             st.pop();
//             int operand2 = st.top(); //ye basically string mein baad wala h
//             st.pop();

//             switch (s[i])
//             {
//             case '+':       //"operator" , ye galat h ku key hum character by character access kr rahe h
//                 st.push(operand1 + operand2);
//                 break;
//             case '-':
//                 st.push(operand1 - operand2);
//                 break;
//             case '*':
//                 st.push(operand1 * operand2);
//                 break;
//             case '/':
//                 st.push(operand1 / operand2);
//                 break;
//             case '^':
//                 st.push(pow(operand1 , operand2));
//                 break;
//             }
//         }
//     }
//     return st.top();
// }

// int main(){
//     cout<< prefix_evaluation("-+7*45+20");
// }
// g++ -o stack D:\sem4\dsa\code\stack.cpp
// g++ -o stack D:\SEMESTER4\PM_Sem4\sem4\dsa\code\stack.cpp




//Postfix Evalution      Yanni postfix di hui h or hum calculation
// #include<iostream>
// #include<stack>
// #include<math.h> // as i am also dealing with power, so calling power method from this file
// using namespace std;

// int postfix_evaluation(string s){
//     stack<int> st;
//     //start from opposite side of operator, means the operators came at R.H.S, so here starts from L.H.S
//     for(int i=0; i<s.length(); i++){
//         if(s[i]>='0' && s[i]<='9'){ //checking if it is operand or not
//             st.push(s[i]-'0');
//         }
//         else{    // if operator then popping out 2 values & apply that operation which comes & pushing its result
//             int op2 = st.top(); //ye basically string mein baad wala
//             st.pop();
//             int op1 = st.top(); //ye basically string mein pheley wala
//             st.pop();

//             switch (s[i])
//             {
//             case '+':
//                 st.push(op1 + op2);
//                 break;
//             case '-':
//                 st.push(op1 - op2);
//                 break;
//             case '*':
//                 st.push(op1 * op2);
//                 break;
//             case '/':
//                 st.push(op1 / op2);
//                 break;
//             case '^':
//                 st.push(pow(op1 , op2));
//                 break;
//             }
//         }
//     }
//     return st.top();
// }

// int main(){
//     cout << postfix_evaluation("46+2/5*7+");
// }
// g++ -o stack D:\sem4\dsa\code\stack.cpp
// g++ -o stack D:\SEMESTER4\PM_Sem4\sem4\dsa\code\stack.cpp



// #include<iostream>
// #include "stack.cpp"
// using namespace std;

// Dynamically  Approach
// int main(){
//     int size;
//     cout << "Enter size of an stack:\n";
//     cin>> size;

//     Stack* obj = new Stack(size);
//     obj->isEmpty();
//     obj->peek();
//     obj->push(5);
//     obj->push(4);
//     obj->push(5);
//     obj->isEmpty();

//     obj->pop();
//     int pop = obj->pop();
//     cout<< "Last pop which i do, here i only store return value out of any other call & its value is: " << pop << endl;
//     obj->isEmpty();
//     obj->peek();
// }

// Statically Approach
// int main(){
//     int size;
//     cout << "Enter size of an array:\n";
//     cin >> size;
//     Stack st(size); //contructor will call

//     cout << "\nSize of the Stack is: " << st.length << endl;
//     st.isEmpty();
//     st.peek();
//     st.push(2);
//     st.push(4);
//     st.push(6);
//     st.push(8);
//     st.push(0);
//     cout << "Pushing done.\n\n";

//     st.isEmpty();
//     st.peek();

//     st.pop();
//     st.pop();
//     cout<< "\nAfter poping out 2 values.\n";
//     st.peek();
//     st.isEmpty();

//     st.pop();
//     int pop = st.pop();
//     cout<< "Last pop which i do, here i only store return value out of any other call & its value is: " << pop << endl;
//     cout<< "\nAfter poping out 2 more values.\n\n";
//     st.peek();
//     st.isEmpty();
// }
// g++ -o stack D:\sem4\dsa\code\stack.cpp
// g++ -o stack D:\SEMESTER4\PM_Sem4\sem4\dsa\code\stack.cpp




// //Taking the size & data as inp from the user, then pushing & poping through LOOPS backwardly
// #include <iostream>
// #include <stack>
// using namespace std;

// void display(stack<int> &st)
// {
//     while (!st.empty())
//     {
//         cout << st.top() << ", ";
//         st.pop();
//     }
// }

// void printing_stack_data(int no_of_data, stack<int> &st)
// // A method can only call those methods which are declared before it but can call the method which are declared after it
// {
//     int i = 0;
//     cout << "Enter data values for the Stack.\n";
//     while (i < no_of_data)
//     {
//         int value;
//         cin >> value;
//         st.push(value);
//         i++;
//     }
//     display(st);
// }

// int main()
// {
//     int no_of_data;
//     stack<int> st;
//     cout << "Enter the no of data you wants to enter in an Stack:\n";
//     cin >> no_of_data;
//     printing_stack_data(no_of_data, st);
// }
// g++ -o stack D:\sem4\dsa\code\stack.cpp
// g++ -o stack D:\SEMESTER4\PM_Sem4\sem4\dsa\code\stack.cpp



// // Taking a string from the user, split it on behlf of space & then print it backwardly
// #include<iostream>
// #include<stack>
// using namespace std;

// void print_string(string s){
//     stack<string> st;
//     // string word="";         //yaha position nhi honi chahiye ku key hr baar space aaega, phr new word store krna hoga
//     for(int i=0; i<s.length(); i++){            // phir ye jo increm ho raha h wo basically space ko cover up krny k lie
//         string word="";
//         while(s[i]!=' ' && i<s.length()){      //jese 3 alpha ka word thaa tou i=3 yaha sey ho jaaega
//             word += s[i];
//             i++;                
//         }
//         st.push(word);
//     }
//     while(!st.empty()){
//         cout << st.top() << " " ;
//         st.pop();       //it is must, b/c if we dont do this then our top will remain same
//     }

// }

// int main(){
//     string s = "I am fine, what about you?";
//     print_string(s);
// }
// g++ -o test D:\sem4\dsa\code\test.cpp


// Actually reversing the data of the STACK
    //M1, do pop from 1 stack then push those into 2nd stack then pop the 2nd stack, but in this we will use 2 Stacks
    //M2, By recursion

// #include<iostream>
// #include<stack>
// using namespace std;
// // Purpose:
// // Initially, stack is: 1,2,3,4,5 (top = 5)
// // Default stack behavior: 5,4,3,2,1 (top = 1 after reversing)
// // Desired outcome: Move 5 to the bottom and keep the rest in original order (1,2,3,4 at the top)
           
// void insertAtBottom(stack<int> &st, int o_top){
// //is mein hm srf top elem(5) ko bottom mein LA rahe h or baqi stack reverse (1,2,3,4(top)) CALL STACK mein
//     if(st.empty()){
//         st.push(o_top);         //5 bottom pr place ho jaaega
//         return;
//     }
//     int c_top = st.top();   
//     cout<< "c_top:" << c_top << endl;
// // c_top :
// // t:1
// // 1    t:2                
// // 1    2       t:3
// // & so on
//     st.pop();
//     insertAtBottom(st, o_top); 

// //agar st.push(c_top)   hata du tou sirf 5 print hoga jo base condition thii
//     st.push(c_top);             // ab ye 1,2,3,4 (4 top) push kr waa rahe h tou is tarah , 1,2,3,4,5 bn jaaega
// };

// void reversing(stack<int> &st){
// // is mein hum sirf top element(5) remove kr rahe h or baqi stack  reverse (4,3,2,1 (top)) CALL STACK mein
//     if(st.empty()){
//         return;
//     }
//     int ele = st.top();
//     cout<< "ele:" << ele << endl;   //5,4,3,2,1
//     st.pop();
//     reversing(st);                  
//     insertAtBottom(st, ele);       // 4,3,2,1(1 on top)
// };

// int main(){
//     stack<int> st;
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);
//     st.push(5);
//     reversing(st);

//     while(!st.empty()){
//         cout<< st.top() << ", ";
//         st.pop();
//     }
//     cout<< endl;
// }
// g++ -o stack D:\sem4\dsa\code\stack.cpp
// g++ -o stack D:\SEMESTER4\PM_Sem4\sem4\dsa\code\stack.cpp