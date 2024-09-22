// // LATER: lec 45 mein reverse key 2nd recursive method , lec 46-52 complete except 50, dont do 47

// // In this code:
// //  1st discuss:  Insertion in 3 places
// //  2nd discuss:  Deletion from any place
// //  3rd discuss:  Traversing whole   L.L
// //  4th discuss:  Reverse Traversing whole
// //  iterative approach          recursive approach
// // 5th discuss:  Middle Node
// // Even        Exact       Odd
// // 6th discuss:  Diplay method

// #include <iostream>
// using namespace std;

// // class Node{      //Bus iska
// struct Node
// {
//     // public:      //or iska farq h, struct my members or inheritance public hotey h By Default
//     // agar ye mein hata du tou phir main() mein accessible nhi ho sakengi ye dono data fields
//     int data;   // Contain data
//     Node *next; // Make pointer b/c it will contain the address of another node & of class Node

//     // Node(int data){ //Making a Constructor of 1 para, which will intialize with provided data value & have 0 as address
//     //     this -> data = data;
//     //     this -> next = NULL;
//     // }
//     // OR
//     Node(int val)
//     { // Making a Constructor of 1 para, which will intialize with provided data value & have 0 as address
//         data = val;
//         next = NULL;
//     }

//     // ``````````````````````````````````````````````````````````````````````````````
//     // Insert a new node at the start of the list
//     void insertAtHead(Node *&head, int val)
//     {
//         Node *newnode = new Node(val);
//         newnode->next = head;
//         head = newnode;
//     }

//     // Insert a new node at the any position(in b/w)
//     void insertAtMiddle(Node *&head, int pos, int val)
//     {
//         if (pos == 1) // to insert element if pos=1
//         {
//             insertAtHead(head, val);
//             return;
//         }
//         else // this does not work for pos =1 b/c we start temp from head
//         {
//             int i = 0;
//             Node *newnode = new Node(val);
//             Node *temp = head;
//             while (i != pos - 2) // for e.g pos is 4 then i=2 b.c pos 4 means want to add 3rd place of i
//             {
//                 temp = temp->next;
//                 i++;
//             }
//             if (temp->next == NULL)
//             { // moving tail to next postition
//                 insertAtTail(head, val);
//                 return;
//             }
//             newnode->next = temp->next;
//             temp->next = newnode;
//         }
//     }

//     // Insert a new node at the end of the list
//     void insertAtTail(Node *&head, int val)
//     { // here we take head as by reference, not by value
//         // This is a reference to a pointer to a Node object. This allows you to modify the actual pointer that was passed in.
//         Node *newnode = new Node(val);

//         if (head == NULL)
//         {
//             head = newnode;
//             return;
//         }

//         Node *temp = head; // temp here is same as head
//         while (temp->next != NULL)
//         {
//             temp = temp->next; // so temp next means head next.
//         }
//         temp->next = newnode;
//     }

//     // ``````````````````````````````````````````````````````````````````````````````
//     void deleteNode(Node *&head, int pos)
//     {
//         if (head == NULL) // no node
//         {
//             cout << "There is no node to delete";
//             return;
//         }
//         else if (pos == 1)
//         {
//             Node *temp = head;
//             head = head->next;
//             delete temp;
//             return;
//         }
//         else
//         {
//             // Node* phichla=head , agla = head;    Wrong, only consider 1st one as pointer & 2nd one as the object
//             Node *phichla = head;
//             Node *agla = head;
//             // for e.g; want to delete from 6th pos means i=5 then i will link i=4->next  with  i=5->next
//             int i = 0, j = 0;
//             while (i != pos - 2)
//             {
//                 phichla = phichla->next;
//                 i++;
//             }
//             while (j != pos - 1)
//             {
//                 agla = agla->next;
//                 j++;
//             }
//             phichla->next = agla->next; // for e.g; 4 node h or 3 delete krni h tou phichla yaha 2nd node hogi or agla 3rd
//             return;
//         }
//     }

//     // ``````````````````````````````````````````````````````````````````````````````
//     void traverse(Node *&head)
//     {
//         for (Node *temp = head; temp != NULL; temp = temp->next) // temp->next != NULL wrong cond phir 1 kum trav krega
//         {
//             cout << temp->data << "->";
//         }
//     }
//     // ``````````````````````````````````````````````````````````````````````````````
//     //Iterative approach
//     Node *revTraverse(Node *head)
//     {
//         if (head == NULL || head->next == NULL)
//         { // if no node or just a single node
//             return head;
//         }
//         else
//         {
//             Node *prev = NULL;
//             Node *curr = head;
//             Node *forw = NULL;
//             while (curr != NULL)
//             {
//                 forw = curr->next;
//                 curr->next = prev;
//                 prev = curr; // curr = forw pheley likh deta, phir p =c likhta tou phir p = f ho jaata ku key c= f thaa
//                 curr = forw;
//             }
//             return prev; // b/c now my head is pointing prev which is actually the last node(r.h.s)
//         }
//     }
//     // ``````````````````````````````````````````````````````````````````````````````
//     // For E.g; 10 -> 20 -> 30 -> 40 -> NULL
//     Node *reverseRecursive(Node *head) // 10       but here they are head, not head->next
//     {
//         // Base case: if the list is empty or has only one node
//         if (head == NULL || head->next == NULL) // head->next:True by 40->next  NULL
//         {
//             return head; // 30
//         }

//         // Recursively reverse the rest of the list
//         Node *newHead = reverseRecursive(head->next); // 20 30 40    these pass as head->next , not as head

//         // Reverse the current node's next pointer
//         head->next->next = head; // as head->next is 40  7 head is 30  So, 40->next = 30 , pointing back
//         head->next = NULL;       // now as head=30 So, head->next means 30->next = NULL

//         // Return the new head of the reversed list
//         return newHead; // it remains 40 as return head actually return 40 which is store in newhead, now it is not changing
//     }
//     // ``````````````````````````````````````````````````````````````````````````````
//     void evenmiddle(Node *head)
//     {
//         if (head == NULL || head->next == NULL)
//         {
//             cout << "\nEither no node or Have single node\n";
//             cout << head->data;
//             return;
//         }
//         else
//         {
//             int i = 0, j = 1;
//             Node *temp1 = head;
//             Node *temp2 = head;

//             while (temp1 != NULL)//jb kbhi traverse krna h tou temp!=NULL ki cond key sath naa key temp->next!=NULL
//             {
//                 i++;
//                 temp1 = temp1->next;
//             }
//             cout << "\n\nTotal no of nodes in this L.L are: " << i << endl;

//             int middle = (i / 2) + 1; // 10/2 ---> 6(5+1)
//             cout << "Middle node position in this L.L is: " << middle << endl;
//             while (j != middle)
//             {
//                 j++;
//                 temp2 = temp2->next;
//             }
//             cout << "Even/Exact Middle node data value in this L.L is: ";
//             cout << temp2->data << endl;
//         }
//     }
//```````````````````````````````````````````````````````````
// void middle_fastapproach(Node *head){
//     // Step 1: Find the middle of the linked list
//     Node *slow = head, *fast = head;
// // fast 2 position move kry ga slow 1 pos, tou jb fast poori list comp kr lega tb slow half of the list tk pohanch jaaega.
//     while (fast && fast->next) {    //both nexessary
// //fast ki cond is liye key fast NULL ko pohanchey ga naa key slow or fast->next key fast key baad wali node exist krti h yaa nhi ku key fast tou 2 node frow move kr raha h.
//         slow = slow->next;          //move 1 forw
//         fast = fast->next->next;    //move 2 forw
//     }
// }

//     // ``````````````````````````````````````````````````````````````````````````````
//     void middle(Node *head)
//     {
//         if (head == NULL || head->next == NULL)
//         {
//             cout << "\nEither no node or Have single node\n";
//             cout << head->data;
//             return;
//         }
//         else
//         {
//             int i = 0, j = 1;
//             Node *temp1 = head;
//             Node *temp2 = head;

//             while (temp1 != NULL)
//             {
//                 i++;
//                 temp1 = temp1->next;
//             }
//             cout << "\n\nTotal no of nodes in this L.L are: " << i << endl;

//             int middle = (i / 2); // 10/2 --->  5
//             cout << "Middle node position in this L.L is: " << middle << endl;
//             while (j != middle)
//             {
//                 j++;
//                 temp2 = temp2->next;
//             }
//             cout << "Middle node data value in this L.L is: ";
//             cout << temp2->data << endl;
//         }
//     }

//     // ``````````````````````````````````````````````````````````````````````````````
//     // Display the linked list
//     void display(Node *head)
//     { // here we take head as by value, not by reference
//         // When you pass head by value to a function, you're passing a copy of the pointer. Modifications to this copy do not affect the original pointer. This means changes to the pointer inside the function won't reflect outside the function.
//         Node *temp = head; // providing address(head) of 1st node
//         while (temp != NULL)
//         {
//             cout << temp->data << " ,";
//             temp = temp->next;
//         }
//         cout << endl; // To move to a new line after displaying the list
//     }
// };

// int main()
// {
//     Node *head = NULL;

//     Node node(0); // Create a local var in stack
//                   // Node node(0); creates a Node object with data 0 on the stack, but it is not linked to the head of the linked list. The display method only traverses and displays nodes that are part of the linked list starting from head.
//     // Node node();   this is also wrong
//     //      LOGIC:
//     //  Node node(0); creates a local instance on the stack destroyed when function ends, while Node *node = new Node(0); creates a dynamic instance on the heap not destroyed & remain in memory until we explicitly do
//     node.insertAtTail(head, 10);
//     node.insertAtTail(head, 20);
//     node.insertAtTail(head, 20);
//     node.insertAtTail(head, 10);
//     cout << "At Tail Only:\n";
//     node.display(head);
//     node.insertAtHead(head, 1000);
//     node.insertAtHead(head, 0);
//     cout << "New At Head Only:\n";
//     node.display(head);
//     node.insertAtTail(head, 30);
//     cout << "New At Tail Only:\n";
//     node.display(head);
//     // agar mein wo pos=1 wali condition ka code nhi likhta or chahye jb bhi bhi mein pos1 pr kuch value likhna chahta tou kuch bhi print nhi karega middle() method ka
//     node.insertAtMiddle(head, 5, 666);
//     // jese agar mein ab yaha node.insertAtMiddle(head, 1, 777); likhu tou ye sirf na sirf isko show nhi kry ga bulkey upper key 2 ko bhi nhi krey ga
//     node.insertAtMiddle(head, 1, 777);
//     node.insertAtMiddle(head, 10, 999); // jb mein last mein add kr raha hu tou value to end mein aa rahi h liken jo tail wala method() h wo usi ko pt kr raha hoga jo us method key through last node bnai gai hogi tou usko update krney key liye if lgaya h middle key method mein
//     cout << "New At Any Position in the Middle Only:\n";
//     node.display(head);

//     cout << "\nTraversing all before deletion:\n";
//     node.traverse(head);
//     node.evenmiddle(head);
//     node.middle(head);
//     cout << "\nReversing all by ITERATION before deletion:\n";
//     head = node.revTraverse(head); // As reverse func returning values so 1st store it then print
//     node.display(head);

//     cout << "\nReversing all by RECURSION before deletion:\n";
//     head = node.reverseRecursive(head);
//     node.display(head);

//     node.deleteNode(head, 6);
//     cout << "\nNow deleting an Element from 6rd position:\n";
//     node.display(head);
//     // cout<< "Now deleting an Element from any position:\n"<< node.deleteNode(head, 3) << node.display(head);
//     // Wrong: key key yaha mein cout ki  continuity mein delete() likh gaya, jb key ye tou kuch return hi nhi kr raha or cout ko value chahiye hoti h print kr waane key liye

//     // g++ -o test D:\sem4\dsa\code\test.cpp
//     // Node *node = new Node(0);   // Create a var in heap
//     // node->insertAtTail(head, 10);
//     // node->insertAtTail(head, 20);
//     // node->insertAtTail(head, 30);
//     // node->display(head);

//     // // Clean up memory, needed when making heap memory. does not need when we make stack
//     // Node *temp;
//     // while (head != NULL) {
//     //     temp = head;
//     //     head = head->next;
//     //     delete temp;
//     // }
//     // delete node; // Don't forget to delete the initial node

//     return 0;
// }

// g++ -o test D:\sem4\dsa\code\test.cpp

// In this code:
// insertion at head, tail, any(basically can handle all cases by some modifications)
// traverse, recursive_rev, palindrome, total nodes
//         is mein mein ney sb sey pheley node bna raha hu tou ye check kr raha h key L.L pheley sey empty h yaa nhi agar empty h tou simply add kr raha h OR AGAR pheley sey node h L.L mein tou phir pooch raha h key ap kis jagah add kr waana chahtey h head, any or tail.
// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     char data; // to take char type data
//     Node *next;

//     Node(char val)
//     {
//         this->data = val;
//         this->next = NULL;
//     }

//     void makeNode(Node *&head, char val, char choice)
//     {
//         Node *newnode = new Node(val);
//         if (head == NULL)
//         { // if no node or just a single node
//             head = newnode;
//             return;
//         }
//         else
//         {
//             if (choice == 'T' || choice == 't')
//             {
//                 insertAtTail(head, newnode); // if want to add +1 nodes at tail
//             }
//             else if (choice == 'H' || choice == 'h')
//             {
//                 insertAtHead(head, newnode); // if want to add +1 nodes at head
//             }
//             else if (choice == 'A' || choice == 'a')
//             {
//                 int pos;
//                 cout << "Enter position at which u want to add Node?\n";
//                 cin >> pos;
//                 if (pos == 1)
//                 {
//                     insertAtHead(head, newnode);
//                     return;
//                 }
//                 else
//                 {
//                     // checking out of bound type limit by traversing all elements.
//                     int total = totalnode(head);
//                     if (pos > total + 1)
//                     { // means can insert at last(1 aagey), but can from +1
//                         cout << "Can't insert at this position, out of bound";
//                     }
//                     else
//                     {
//                         Node *phichla = head;
//                         Node *agla = head;
//                         int i = 1, j = 1;
//                         while (i < pos - 1)
//                         {
//                             phichla = phichla->next;
//                             i++;
//                         }
//                         while (j != pos)
//                         {
//                             agla = agla->next;
//                             j++;
//                         }
//                         phichla->next = newnode;
//                         newnode->next = agla;
//                     }
//                 }
//             }
//             else
//             {
//                 cout << "Invalid option\n";
//             }
//         }
//     }

//     void insertAtHead(Node *&head, Node *newnode)
//     {
//         newnode->next = head;
//         head = newnode;
//     }

//     void insertAtTail(Node *&head, Node *newnode)
//     {
//         Node *temp = head;
//         while (temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         temp->next = newnode;
//     }

//     int totalnode(Node *head)
//     {
//         Node *temp = head;
//         int total = 0;
//         while (temp != NULL)
//         {
//             total++;
//             temp = temp->next;
//         }
//         cout << "Total no of nodes in L.L:" << total << endl;
//         return total;
//     }

//     void traverse(Node* head){
//         Node *temp = head;
//         while (temp != NULL)
//         {
//             cout << temp->data << "->";
//             temp = temp->next;
//         }
//         cout << endl;
//     }

//     Node* rec_reverse(Node* head){
//         if(head == NULL || head->next == NULL){
//             return head;
//         }
//         Node *newhead = rec_reverse(head->next);
//         head->next->next = head;
//         head->next = NULL;
//         return newhead;
//     }
// //````````````````````````````````````````````````````````````````````````````````
//     bool isPalindrome(Node* head) {
//     if (!head || !head->next) {         //(head == NULL || head->next == NULL)      SAME
//         return true;
//     }

//     // Step 1: Find the middle of the linked list
//     Node *slow = head, *fast = head;
// // fast 2 position move kry ga slow 1 pos, tou jb fast poori list comp kr lega tb slow half of the list tk pohanch jaaega.
//     while (fast && fast->next) {    //both necessary
// //fast ki cond is liye key fast NULL ko pohanchey ga naa key slow or fast->next key fast key baad wali node exist krti h yaa nhi ku key fast key baad bhi koi node nhi tb bhi aagey move krna nhi chahiye
// //while(fast && fast->next): This condition will keep the loop running as long as both fast and fast->next are not NULL.
// //while(!fast && !fast->next): This cond wil only run loop when fast and fast->next are NULL.
//         slow = slow->next;          //move 1 forw
//         fast = fast->next->next;    //move 2 forw
//     }

//     // Step 2: Reverse the second half of the linked list
//     Node* secondHalf = rec_reverse(slow);

//     // Step 3: Compare the first half and the reversed second half
//     Node *firstHalf = head, *temp = secondHalf;
//     while (temp) {          //yaha temp is liye likha key half key baad ye NULL ko pohanch jaaega ku key start hi half sey ho rha h
//         if (firstHalf->data != temp->data) {
//             return false; // Not a palindrome
//         }
//         firstHalf = firstHalf->next;
//         temp = temp->next;
//     }

//     // Optional Step 4: Restore the original list by reversing the second half again
//     rec_reverse(secondHalf);

//     return true; // It is a palindrome
// }

//     void display(Node *head)
//     {
//         traverse(head);
//     }
// }; // Semi-colon is must after class end

// int main()
// {
//     Node *head = NULL;
//     Node node(0);

//     // string message = "Enter:\n\tT or t to add node at the Tail.\n\tElse Enter H or h to add node at the Head.\n\tOr Enter A or a to add node in between at any place\n";
//     // char choice;

//     // cout << message;
//     // // cin >> choice << endl;   WRONG
//     // cin >> choice;
//     // node.makeNode(head, 'Z', choice);
//     // node.makeNode(head, 'E', choice);
//     // node.makeNode(head, 'E', choice);
//     // node.display(head);

//     // cout << message;
//     // cin >> choice;
//     // node.makeNode(head, 'S', choice);
//     // node.makeNode(head, 'H', choice);
//     // node.display(head);

//     // cout << message;
//     // cin >> choice;
//     // node.makeNode(head, 'A', choice);
//     // node.makeNode(head, 'N', choice);
//     // node.display(head);

//     // cout << message;
//     // cin >> choice;
//     // node.makeNode(head, 'J', choice);
//     // node.makeNode(head, 'A', choice);
//     // node.makeNode(head, 'N', choice);
//     // node.display(head);

//     int nodes = node.totalnode(head);
//     cout << nodes;

//     string message = "Enter:\n\tT or t to add node at the Tail.\n\tElse Enter H or h to add node at the Head.\n\tOr Enter A or a to add node in between at any place\n";
//     char choice;
//     cout << message;
//     cin >> choice;

//     node.makeNode(head, 'l', choice);
//     node.makeNode(head, 'a', choice);
//     node.makeNode(head, 'E', choice);
//     node.makeNode(head, 'a', choice);
//     node.makeNode(head, 'l', choice);
//     node.display(head);

//     //jb ye rev kr waa kr phir palindrome kr waa raha hu tou hamesha hi result palindrome dey raha h iska koi bhund h
//     // reason: When you call node.rec_reverse(head);, you reverse the list and head now points to the reversed list. The isPalindrome method operates on the head of the list, which is now pointing to the reversed list. Hence, the palindrome check is done on the reversed list, not the original one.
//     // cout<< "Reverse of the L.L:\n";
//     // Node* rev = node.rec_reverse(head);
//     // node.display(rev);
//     // // cout << rev ; This is wrong approach, will show resut in hexadec form

//     bool palind = node.isPalindrome(head);
//     if(palind == true){
//         cout<< "It is a Palindrome";
//     }
//     else{
//         cout<< "It is NOT a Palindrome";
//     }
// }
// g++ -o test D:\sem4\dsa\code\test.cpp
// g++ -o test D:\SEMESTER4\PM_Sem4\sem4\dsa\code\test.cpp

