#include "Variable.h"
//--------------Variable class (vector)
//constructor

Variable::Variable() {
    { value.push_back(0); }
    Dstype = "var";
};

string Variable::gettype() {
    return Dstype;
};

//copy constructor
Variable :: Variable(const Variable& other) {
    value.push_back(other.value[0]);
}

// if boolean variable true print message
void Variable::VarIfTrue(bool condition, string message) {
    if (condition) {
        cout << message << endl;
    }
}

// if boolean variable not true print message
void Variable::VarIfFalse(bool condition, string message) {
    if (!condition) {
        cout << message << endl;
    }
}


int Variable::Vargetvalue() {
    return value[0];
};
