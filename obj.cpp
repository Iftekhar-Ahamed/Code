#include <iostream>
using namespace std;
class Student
{

    string name;
    int roll, mark;

public:
    Student()
    {
        name = "";
        roll = mark = 0;
    }

    Student(string v1, int v2, int v3)
    {
        name = v1;
        roll = v2, mark = v3;
    }
    int getMark()
    {
        return mark;
    }
    void print()
    {
        cout << "Name :" << name << endl
             << "Roll :" << roll << endl
             << "Mark :" << mark << endl;
    }
};
void mark(Student ob[])
{
    Student ans = Student("", 0, 0);

    for (int i = 0; i < 5; i++)
    {
        if (ans.getMark() <= ob[i].getMark())
        {
            ans = ob[i];
        }
    }
    cout << "Highest Stdent details : ";
    ans.print();
}

int main()
{
    Student ob[5];
    for (int i = 0; i < 5; i++)
    {
        string name;
        int roll, mark;
        cout << "Enter Name :";
        cin >> name;

        cout << "Enter Roll :";
        cin >> roll;

        cout << "Enter Mark :";
        cin >> mark;
        ob[i] = Student(name, roll, mark);
    }
    mark(ob);
    return 0;
}