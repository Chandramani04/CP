#include "bits/stdc++.h";
using namespace std;

class Student {
    string name;
    int rollNo;
    static int count;

   public:
    Student(string name, int rollNo) {
        this->name = name;
        this->rollNo = rollNo;
    }
    void display() {
        cout << "Name: " << name << " Roll No: " << rollNo << endl;
    }
    static void getCount() {
        cout << "Count: " << count << endl;
    }
};
int Student::count = 0;  // static variable initialization
signed main() {
    Student s1("Rahul", 1);
    s1.display();

    return 0;
}
