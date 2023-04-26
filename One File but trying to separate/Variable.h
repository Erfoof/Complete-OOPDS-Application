#pragma once
#include "Datastructure.h"
class Variable :public Datastructure {
private:
    vector<int> value;
    string Dstype;
public:
    // constructor
    Variable();
    // destructor
    ~Variable() { value.clear(); }
    // copy constructor
    Variable(const Variable& other);

    string gettype();


    // declare variable
    void VarAssign(int val) { value[0] = val; }
    // operator overloading for assigning one variable to another
    Variable& operator=(const Variable& other) { value[0] = other.value[0]; return *this; }
    // operator overloading for adding value to variable
    Variable& operator+(int val) { value[0] += val; return *this; }
    // operator overloading for adding one variable to another
    Variable& operator+(const Variable& other) { value[0] += other.value[0]; return *this; }
    // operator overloading for subtracting value from variable
    Variable& operator-(int val) { value[0] -= val; return *this; }
    // operator overloading for subtracting one variable from another
    Variable& operator-(const Variable& other) { value[0] -= other.value[0]; return *this; }
    // operator overloading for multiplying variable by value
    Variable& operator*(int val) { value[0] *= val; return *this; }
    // operator overloading for multiplying one variable by another
    Variable& operator*(const Variable& other) { value[0] *= other.value[0]; return *this; }
    // operator overloading for dividing variable by value
    Variable& operator/(int val) { value[0] /= val; return *this; }
    // operator overloading for dividing one variable by another
    Variable& operator/(const Variable& other) { value[0] /= other.value[0]; return *this; }
    // operator overloading for mod variable by value
    Variable& operator%(int val) { value[0] %= val; return *this; }
    // operator overloading for mod variable by another variable
    Variable& operator%(const Variable& other) { value[0] %= other.value[0]; return *this; }
    // print variable
    void print() { cout << value[0]; }

    int Vargetvalue();

    // if boolean variable true print message
    void VarIfTrue(bool condition, string message);
    // if boolean variable not true print message
    void VarIfFalse(bool condition, string message);


};

