#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct User
{
    char* name = new char;
    int age;
};

template <typename T>
struct Array
{
    T* items;
    int size;
};

template <typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void ArraySort(Array<T>& array, bool (*Predicate)(T a, T b))
{
    for (int i = 0; i < array.size; i++)
        for (int j = array.size - 1; j > i; j--)
            if (Predicate(array.items[j], array.items[j - 1]))
                Swap(array.items[j], array.items[j - 1]); 
}

int main()
{
    srand(time(nullptr));

    Array<int> arrInt;
    arrInt.size = 10;
    arrInt.items = new int[arrInt.size];

    for (int i = 0; i < arrInt.size; i++)
        arrInt.items[i] = rand() % 100;

    for (int i = 0; i < arrInt.size; i++)
        cout << arrInt.items[i] << " ";
    cout << "\n";

    ArraySort<int>(arrInt, [](int a, int b)->bool {
        return a < b;
        });

    for (int i = 0; i < arrInt.size; i++)
        cout << arrInt.items[i] << " ";
    cout << "\n";

    
    Array<User> users;
    users.size = 5;
    users.items = new User[users.size];

    strcpy(users.items[0].name, "Leo");
    users.items[0].age = 34;

    strcpy(users.items[1].name, "Bob");
    users.items[1].age = 22;

    strcpy(users.items[2].name, "Tim");
    users.items[2].age = 19;

    strcpy(users.items[3].name, "Joe");
    users.items[3].age = 41;

    strcpy(users.items[4].name, "Roy");
    users.items[4].age = 22;

    for (int i = 0; i < users.size; i++)
        cout << users.items[i].name << " " << users.items[i].age << "\n";
    cout << "\n";

    ArraySort<User>(users, [](User a, User b) {
        return a.age < b.age;
        });

    for (int i = 0; i < users.size; i++)
        cout << users.items[i].name << " " << users.items[i].age << "\n";
    cout << "\n";

    ArraySort<User>(users, [](User a, User b) {
        return strcmp(a.name, b.name) < 0;
        });

    for (int i = 0; i < users.size; i++)
        cout << users.items[i].name << " " << users.items[i].age << "\n";
    cout << "\n";
}
