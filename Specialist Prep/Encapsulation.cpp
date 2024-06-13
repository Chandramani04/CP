#include <bits/stdc++.h>
using namespace std;

// Encapsulation is the process of wrapping up of data and functions into a single unit called class.
// It is a mechanism that restricts direct access to some of the object's components.
// Encapsulation is used to hide the values or state of a structured data object inside a class, preventing
// unauthorized parties' direct access to them.

// Variables of a class are hidden from other classes, and can be accessed only through the methods of their current class.
// This is called data hiding.

class Encapsulation {
   private:
    int x;  // data hidden from outside world
   public:
    void set(int a) {
        x = a;
    }
    int get() {
        return x;
    }
};

// usecase :

class Student {
   private:
    string name;
    int rollNo;

   public:
    void setName(string name) {
        this->name = name;
    }
    void setRollNo(int rollNo) {
        if (rollNo <= 0) {
            cout << "Invalid Roll No" << endl;
        } else
            this->rollNo = rollNo;
    }
    void display() {
        cout << "Name: " << name << " Roll No: " << rollNo << endl;
    }
};

signed main() {
    Student s1;
    s1.setName("Rahul");
    s1.setRollNo(1);
    s1.display();
}