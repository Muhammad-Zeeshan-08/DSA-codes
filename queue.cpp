// Queue Implementation through Array
#include<iostream>
using namespace std;

struct Queue_Array{
    int* arr, length, front, back;

    Queue_Array(int size){
        arr = new int[size];
        front = back = -1;
        length = size;
    }

    void enqueue(int value){
        if(back == length-1){ //checking boundary/limit   as back starts from -1
            cout << "Can't Enqueue due to Overflow State.\n";
        }
        else if(back==-1 && back<length){        //1st element insertion
            back++; 
            front++;     //is ki wajah sey if, elif bnana para ku key front ko bhi tou 0 krna jb element add ho
            arr[back] = value;
        }
        else if(back>-1 && back<length){   // other than 1st element
            back++; 
            arr[back] = value;
        }
    }

    void dequeue(){
        if(front > back){
            cout << "Cant't dequeue anymore due to Underflow State.\n";
        }
        else{
            front++;  // dequeue mein front sey delete hota h
        }
    }

    void peek(){//peek represent that element which will be deleted 
        if(front == -1 || front>back){
            cout << "No element at Top as Queue is Empty.\n";
        }
        else{
            cout << "The top of Queue is: "<< arr[front] << endl;
        }

    }

    void empty(){
        if(front == -1 || front>back){    
            cout << "Queue is Empty.\n";
        }
        else{
            cout << "Queue is not Empty.\n";
        }
    }

//For-Each Loop doesn't work well with dynamically allocated arrays. For-Each loop needs to know the size of the array in order to iterate over its elements. In the case of dynamic arrays, there's no built-in size information that the loop can use.
    // void display(){
    //     for(int x:arr){
    //         cout << arr[x] << ", ";
    //     }
    //     cout<< endl;
    // }
    void display(){
        // for(int i=front ; front!=back ; front++){
//Ye galat logic h, mujhey front ko modify nhi krna chahiye, ku key phir saari logic kharab ho jaaegi for future
        for(int i=front ; i<=back ; i++){
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
};

int main(){
    Queue_Array qa(5);      // Have to pass size as constructor took 1 para which is size

    qa.empty();
    qa.peek();
    qa.enqueue(1);
    qa.enqueue(3);
    qa.enqueue(5);
    qa.enqueue(7);
    qa.enqueue(9);
    qa.enqueue(11);
    qa.display();
    qa.empty();
    qa.peek();

    qa.dequeue();
    qa.dequeue();
    qa.dequeue();
    qa.display();
    qa.empty();
    qa.peek();
}
// g++ -o queue D:\sem4\dsa\code\queue.cpp
// g++ -o queue D:\SEMESTER4\PM_Sem4\sem4\dsa\code\queue.cpp



// // Queue Implementation through Linked List
// #include<iostream>
// using namespace std;

// class Queue_LL{
//     public:
//         int data, front, back;
//         int length = 5;
//         Queue_LL* next;


//         Queue_LL(int value){
//             data = value;
//             next = NULL;
//             front = back = -1;
//         }

//         void enqueue(Queue_LL* &head, int value){
//             if(back == length-1){
//                 cout << "Can't enqueue an element Due to Overflow State.\n";
//             }
//             else{
//                 Queue_LL* newnode = new Queue_LL(value);
//                 if(front == -1 || head == NULL){
//                     head = newnode;
//                     front = back = 0;
//                     return;
//                 }
//                 else{
//                     Queue_LL* temp = head;
//                     while(temp->next != NULL){
//                         temp = temp->next;
//                     }
//                     temp->next = newnode;
//                     back++;
//                     return;
//                 }

//             }
//         }

//         void dequeue(Queue_LL* &head){
//             if(front == -1 || front>back){
//                 cout<< "Can't Dequeue, as Queue is Empty.\n";
//             }
//             else{
//                     Queue_LL* temp = head->next;
//                     head = temp;
//                     front++;
//                     return;    
//             }
//         }

//         void empty(Queue_LL* head){
//             if(front == -1 || front>back){
//                 cout<< "Queue is Empty.\n";
//             }      
//             else{
//                 cout<< "Queue is not Empty.\n";
//             }
//         }

//         void peek(Queue_LL* head){
//             if(front == -1 || front>back){
//                 cout<< "Nothing is at the Top as Queue is Empty.\n";
//             }  
//             else{
//                 cout << "Value at the Top of the Queue: " << head->data << endl;
//             }
//         }

//         void display(Queue_LL* head){
//             if(front == -1 || front>back){
//                 cout<< "Queue is Empty, nothing to display\n";
//             }
//             else{
//                 Queue_LL* temp = head;
//                 while(temp != NULL){
//                     cout << temp->data << ",";
//                     temp = temp->next;
//                 }
//                 cout << endl;
//             }
//         }
// };

// int main(){
//     Queue_LL* head = 0;
//     Queue_LL qll(0);
//     cout << "The size of Linked List to store/hold elements are: 5\n" <<endl;

//     qll.empty(head);
//     qll.peek(head);
//     qll.enqueue(head, 1);   
//     qll.enqueue(head, 3);  
//     qll.enqueue(head, 5);  
//     qll.enqueue(head, 7);  
//     qll.enqueue(head, 9);  
//     qll.display(head);
//     qll.empty(head);
//     qll.peek(head);  
//     cout<<endl; 

//     qll.dequeue(head);
//     qll.dequeue(head);
//     qll.display(head);
//     qll.empty(head);
//     qll.peek(head);   
// }
// g++ -o queue D:\sem4\dsa\code\queue.cpp
// g++ -o queue D:\SEMESTER4\PM_Sem4\sem4\dsa\code\queue.cpp










// // Queue Implementation through Stack
// #include<iostream>
// #include "stack.cpp"
// using namespace std;

// int main(){
//     int size = 5;

//     Stack st1(size);
//     Stack st2(size);

// //Enqueue:
//     st1.push(1);   st1.push(3);     st1.push(5);    st1.push(7);    st1.push(9);    
//     st1.display();      //9(top),7,5,3,1

//     for(int i=1; i<=size; i++){
//         int val = st1.pop();
//         st2.push(val);
//     }
// //Method2:
// // st2.push(st1.pop());   st2.push(st1.pop());   st2.push(st1.pop());    st2.push(st1.pop());    st2.push(st1.pop());   
//     st2.display();      //1(top),3,5,7,9


// //Dequeue:
//     cout<< "How many times u want to dequeue?:\n";
//     int times;
//     cin >> times;
//     if(times > size){
//         cout << "Can't pop upto your input, as the size of Queue is: " << size << endl;  
// //yaha pop is liye kia ku key agar, pop naa kru or baad mein display ya peek ya empty call kraounga tou wo Not empty type dikhaenge
//         for(int i=1; i<=size; i++){
//            int val = st2.pop();
//         }
//     }
//     else{ 
//         for(int i=1; i<=times; i++){
//            int val = st2.pop();
//         }
//     }

//     cout<< "Remaining elements of Queue after poping out:\n";
//     st2.display();
//     st2.peek();
// }
// g++ -o test D:\sem4\dsa\code\test.cpp