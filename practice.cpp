#include<iostream>
using namespace std;

class practice{
    public:
        practice(){
            cout << "Hello World";
        }
};


// {both can be used to modify the original variable in a function.}
//  Call by Reference                Call by Address

// Call by Address / Call by Dereference:
void modify(int *ptr) {  // Function takes a pointer (address)
    *ptr = 10;           // Dereferencing the pointer to modify the actual value
}
int main() {
    int a = 5;
    modify(&a);          // Pass the address of 'a'
    cout << a;           // Output will be 10
}
       
//  Call by Reference:
void modify(int &ref) {  // Function takes a reference (not a pointer)
    ref = 10;            // Directly modifies the original variable
}
int main() {
    int a = 5;
    modify(a);           // Pass 'a' by reference
    cout << a;           // Output will be 10
}