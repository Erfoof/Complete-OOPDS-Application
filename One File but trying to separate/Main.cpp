#include "Datastructure.h"
#include "BST.h"
#include "DoubleLinkedList.h"
#include "SinglyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Variable.h"
#include <unordered_map>
#include <cmath>
#include <sstream>
#include <cctype> 
#include <list> //used for parsing algorithm
#include <cstdlib>
#include <fstream>
using namespace std;


//parsing algorithm. Storing values in a list and transforming the words to lowercase.

list<string> parseInput(const string& input) {
    list<string> words;
    string word = "";
    for (const char& c : input) {
        if (c != ' ') {
            word += c;
        }
        else {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            words.push_back(word);
            word = "";
        }
    }
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    words.push_back(word);
    return words;
}



//functions to create each DS dynamically. Each of them gets a pointer of the sub class and assigns it to pointer of base class (Datastructure)
//This is where run time polymorphism is used
Datastructure* newBST() {
    Datastructure* ptr = new BST();
    return ptr;
};

Datastructure* newDLL() {
    Datastructure* ptr = new DoubleLinkedList();
    return ptr;

};

Datastructure* newSLL() {
    Datastructure* ptr = new SinglyLinkedList();
    return ptr;
};

Datastructure* newStack() {
    Datastructure* ptr = new Stack();
    return ptr;
};

Datastructure* newQueue() {
    Datastructure* ptr = new Queue();
    return ptr;
};

Datastructure* newVariable() {
    Datastructure* ptr = new Variable();
    return ptr;
};






int main() {
    //map for storing all datastructure addresses. One map is only used because all datastructure addresses are stored using the BASE class.
    unordered_map<string, Datastructure* > DS;

    //maps for pointers. The pointers store the current location of a user defined pointer in either a SLL or a DLL. Map is used because the user
    //can make as many pointers as they want for the SLL and DLL, and use each pointer to traverse the datastructures.
    //The map stores the address of each location and uses its name as a key.
    unordered_map<string, DLLNode* > DLLpointer;
    unordered_map<string, SLLNode* > SLLpointer;


    string input;
    double num;
    double num2;
    bool DLLisend;
    bool SLLisend;
    bool DLLishead;
    bool SLLishead;

    fstream inputfile;

    //while loop that continues until the input is "end"
    while (input != "end") {
        

        getline(cin, input);
        if (input == "end") {
            break;
        }
        list<string> words = parseInput(input);
        string word1, word2, word3, word4;
        int i = 1;

        //adds first 4 words, the rest are ignored.
        for (auto& word : words) {
            switch (i) {
            case 1:
                word1 = word;
                break;
            case 2:
                word2 = word;
                break;
            case 3:
                word3 = word;
                break;
            case 4:
                word4 = word;
                break;
            }
            if (i == 4) break;
            i++;
        }


        //reading from a file and changing values for word1-word4.
        if (word1 == "file") {
            inputfile.open("Input.txt", ios::in);
            if (inputfile.is_open()) {
                string line;
                while (getline(inputfile, line)) {
                    list<string> words = parseInput(line);
                    int i = 1;
                    for (auto& word : words) {
                        switch (i) {
                        case 1:
                            word1 = word;
                            break;
                        case 2:
                            word2 = word;
                            break;
                        case 3:
                            word3 = word;
                            break;
                        case 4:
                            word4 = word;
                            break;
                        }
                        if (i == 4) break;
                        i++;
                    }
                }
            
            };
            inputfile.close();

        }




        //creating a datastructure. Depending on the user's choice, the right function for making a new DS is called and the datastructure
        //is created at run time.
        if (word1 == "var") {
            if (word2 == "bst") {
                DS[word3] = newBST();
            }
            else if (word2 == "dll") {
                DS[word3] = newDLL();
            }
            else if (word2 == "sll") {
                DS[word3] = newSLL();
            }
            else if (word2 == "stack") {
                DS[word3] = newStack();
            }
            else if (word2 == "queue") {
                DS[word3] = newQueue();
            }
            else if (word2 == "variable") {
                DS[word3] = newVariable();

            };
        }

        //clear screen
        else if (word1 == "cls") {
            system("cls");
        }

        //deleting datastructure.
        else if (word1 == "delete") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                delete DS[word2];
                cout << "Datastructure deleted!" << endl;
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }


        //printing datastructure
        else if (word1 == "print") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                if (DS.count(word2) > 0)
                {
                    DS[word2]->print(); cout << endl;
                }
                else
                    cout << "Datastructure does not exist" << endl;
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }


        //sorting datastructure. Syntax is: sort ascend/descend [DS NAME]
        else if (word1 == "sort") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                if (word2 == "ascend") {
                    DS.at(word3)->sort_ascend();
                }
                else if (word2 == "descend") {
                    DS.at(word3)->sort_descend();
                }
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }


        //cloning datastructure.
        else if (word1 == "clone") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            if (DS[word2]->gettype() == "bst") {
                BST* derivedPtr = dynamic_cast<BST*>(DS[word2]);
                DS[word3] = new BST(*derivedPtr);
            }   

            else if (DS[word2]->gettype() == "dll") {
                DoubleLinkedList* derivedPtr = dynamic_cast<DoubleLinkedList*>(DS[word2]);
                DS[word3] = new DoubleLinkedList(*derivedPtr);

            }
            else if (DS[word2]->gettype() == "sll") {
                SinglyLinkedList* derivedPtr = dynamic_cast<SinglyLinkedList*>(DS[word2]);
                DS[word3] = new SinglyLinkedList(*derivedPtr);

            }
            else if (DS[word2]->gettype() == "stack") {
                Stack* derivedPtr = dynamic_cast<Stack*>(DS[word2]);
                DS[word3] = new Stack(*derivedPtr);
            }
            else if (DS[word2]->gettype() == "queue") {
                Queue* derivedPtr = dynamic_cast<Queue*>(DS[word2]);
                DS[word3] = new Queue(*derivedPtr);
            }

            else if (DS[word2]->gettype() == "var") {
                Variable* derivedPtr = dynamic_cast<Variable*>(DS[word2]);
                DS[word3] = new Variable(*derivedPtr);

            };

        }

        //--------------------------------------Methods for the variable datastructure; adding, making equal to, subtracting, dividing, multiplying & modding.

        else if (word1 == "=") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            bool contains_number = false;
            for (int i = 0; i < word3.length(); i++) {
                if (isdigit(word3[i])) {
                    contains_number = true;
                    break;
                }
            }
            try {
                if (contains_number) {
                    num = stod(word3);
                    DS.at(word2)->VarAssign(num);
                }
                else {
                    Variable* derivedPtr = dynamic_cast<Variable*>(DS[word3]); //downcasting to access copy constructor 
                    DS[word3] = derivedPtr;
                    DS[word3]->VarAssign(DS[word2]->Vargetvalue());
                }
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }


        else if (word1 == "+") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            bool contains_number = false;
            for (int i = 0; i < word3.length(); i++) {
                if (isdigit(word3[i])) {
                    contains_number = true;
                    break;
                }
            }
            try {
                if (contains_number) {
                    num = stod(word3);
                    dynamic_cast<Variable*>(DS.at(word2))->VarAssign(dynamic_cast<Variable*>(DS.at(word2))->Vargetvalue() + num);
                }
                else {
                    dynamic_cast<Variable*>(DS.at(word2))->VarAssign(dynamic_cast<Variable*>(DS.at(word2))->Vargetvalue() + dynamic_cast<Variable*>(DS.at(word3))->Vargetvalue());
                }
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }




        else if (word1 == "-") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            bool contains_number = false;
            for (int i = 0; i < word3.length(); i++) { //checks if word3 contains a number. if its a number, an assumption is made that the user wants to subtract a value to the varaible.
                if (isdigit(word3[i])) {
                    contains_number = true;
                    break;
                }
            }
            try {
                if (contains_number) {
                    num = stod(word3);//getting pointer to sub class and assigning it to itself and subtracting the number specified in the input.
                    dynamic_cast<Variable*>(DS[word2])->VarAssign(dynamic_cast<Variable*>(DS[word2])->Vargetvalue() - num);
                }
                else {
                    //using dynamic casting to be able to access the sub class pointers. And then using Varassign to assign the values retrieved from word2(operand)  and word3(operator)
                    dynamic_cast<Variable*>(DS[word2])->VarAssign(dynamic_cast<Variable*>(DS[word2])->Vargetvalue() - dynamic_cast<Variable*>(DS[word3])->Vargetvalue());
                }
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }


        else if (word1 == "*") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            bool contains_number = false;
            for (int i = 0; i < word3.length(); i++) { //checks if word3 contains a number. if its a number, an assumption is made that the user wants to subtract a value to the varaible.
                if (isdigit(word3[i])) {
                    contains_number = true;
                    break;
                }
            }
            try {
                if (contains_number) {
                    num = stod(word3);//getting pointer to sub class and assigning it to itself and subtracting the number specified in the input.
                    dynamic_cast<Variable*>(DS[word2])->VarAssign(dynamic_cast<Variable*>(DS[word2])->Vargetvalue() * num);
                }
                else {
                    //using dynamic casting to be able to access the sub class pointers. And then using Varassign to assign the values retrieved from word2(operand)  and word3(operator)
                    dynamic_cast<Variable*>(DS[word2])->VarAssign(dynamic_cast<Variable*>(DS[word2])->Vargetvalue() * dynamic_cast<Variable*>(DS[word3])->Vargetvalue());
                }
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }

        }

        else if (word1 == "/") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            bool contains_number = false;
            for (int i = 0; i < word3.length(); i++) { //checks if word3 contains a number. if its a number, an assumption is made that the user wants to subtract a value to the varaible.
                if (isdigit(word3[i])) {
                    contains_number = true;
                    break;
                }
            }
            try {
                if (contains_number) {
                    num = stod(word3);//getting pointer to sub class and assigning it to itself and subtracting the number specified in the input.
                    dynamic_cast<Variable*>(DS[word2])->VarAssign(dynamic_cast<Variable*>(DS[word2])->Vargetvalue() / num);
                }
                else {
                    //using dynamic casting to be able to access the sub class pointers. And then using Varassign to assign the values retrieved from word2(operand)  and word3(operator)
                    dynamic_cast<Variable*>(DS[word2])->VarAssign(dynamic_cast<Variable*>(DS[word2])->Vargetvalue() / dynamic_cast<Variable*>(DS[word3])->Vargetvalue());
                }
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }

        }

        else if (word1 == "%") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            int intnum = stod(word3);
            bool contains_number = false;
            for (int i = 0; i < word3.length(); i++) { //checks if word3 contains a number. if its a number, an assumption is made that the user wants to subtract a value to the varaible.
                if (isdigit(word3[i])) {
                    contains_number = true;
                    break;
                }
            }
            try {
                if (contains_number) {
                    num = stod(word3);//getting pointer to sub class and assigning it to itself and subtracting the number specified in the input.
                    dynamic_cast<Variable*>(DS[word2])->VarAssign(dynamic_cast<Variable*>(DS[word2])->Vargetvalue() % intnum);
                }
                else {
                    //using dynamic casting to be able to access the sub class pointers. And then using Varassign to assign the values retrieved from word2(operand)  and word3(operator)
                    dynamic_cast<Variable*>(DS[word2])->VarAssign(dynamic_cast<Variable*>(DS[word2])->Vargetvalue() % dynamic_cast<Variable*>(DS[word3])->Vargetvalue());
                }
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }

        }



        //--------------------------------------Methods for DLL & SLL

        else if (word1 == "adde") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                num = stod(word3);
                if (DS[word2]->gettype() == "dll") {
                    DS[word2]->DLLaddNodeToEnd(num);
                }
                else if (DS[word2]->gettype() == "sll") {
                    DS[word2]->SLLaddNodeToEnd(num);
                }
                else {
                    cout << "This datastructure does not support the method called" << endl;
                };
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }

        else if (word1 == "dele") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }

            try {
                if (DS[word2]->gettype() == "dll") {
                    DS[word2]->DLLdeleteNodeFromEnd();
                }
                else if (DS[word2]->gettype() == "sll") {
                    DS[word2]->SLLdeleteNodeFromEnd();
                }
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }

        else if (word1 == "delf") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                if (DS[word2]->gettype() == "dll") {
                    DS[word2]->DLLdeleteNodeFromFront();
                }
                else if (DS[word2]->gettype() == "sll") {
                    DS[word2]->SLLdeleteNodeFromFront();
                }
                else {
                    cout << "This datastructure does not support the method called" << endl;
                };
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }


        else if (word1 == "addf") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                if (DS[word2]->gettype() == "dll") {
                    num = stod(word3);
                    DS[word2]->DLLaddNodeToFront(num); //needs to be casted
                }
                else if (DS[word2]->gettype() == "sll") {
                    num = stod(word3);
                    DS[word2]->SLLaddNodeToFront(num); // needs to be casted
                }
                else {
                    cout << "This datastructure does not support the method called" << endl;
                };
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }



        else if (word1 == "adda") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                if (DS[word2]->gettype() == "dll") {
                    num = stod(word3);
                    num2 = stod(word4);
                    DS[word2]->DLLinsertAfter(num2, num); 
                }
                else if (DS[word2]->gettype() == "sll") {
                    num = stod(word3);
                    num2 = stod(word4);
                    DS[word2]->SLLinsertAfter(num2, num); 
                }
                else {
                    cout << "This datastructure does not support the method called" << endl;
                };
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }



        // creates new pointer with name of (word3) and points at the start.
        else if (word1 == "ptrstart") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                if (DS[word2]->gettype() == "dll") {
                    DLLpointer[word3] = DS[word2]->DLLpointToBeginning(); //returns a ptr address that is at the beginning of list
                }
                else if (DS[word2]->gettype() == "sll") {
                    SLLpointer[word3] = DS[word2]->SLLpointToBeginning();
                }
                else {
                    cout << "This datastructure does not support the method called" << endl;
                };
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }

        }


        // creates new pointer with name of (word3) and points at the start.
        else if (word1 == "ptrend") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                if (DS[word2]->gettype() == "dll") {
                    DLLpointer[word3] = DS[word2]->DLLpointToEnd(); //returns a ptr address that is at the beginning of list
                }
                else if (DS[word2]->gettype() == "sll") {
                    SLLpointer[word3] = DS[word2]->SLLpointToEnd();
                }
                else {
                    cout << "This datastructure does not support the method called" << endl;
                };
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }

        //!!!new syntax of getnode : getnode [DSName] [VariableName] [PTRName]!!!!

        else if (word1 == "getnode") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                if (DS[word2]->gettype() == "dll") {
                    
                    DS[word3] = newVariable();//new variable made based on input
                    DS[word3]->VarAssign(DS[word2]->DLLgetValueAtPointer(DLLpointer[word4]));
                    cout << DLLpointer[word4]->data;
                    cout << endl;
                }
                else if (DS[word2]->gettype() == "sll") {
                    DS[word3] = newVariable();//new variable made based on input
                    DS[word3]->VarAssign(DS[word2]->SLLgetValueAtPointer(SLLpointer[word4]));
                    cout << SLLpointer[word4]->data;
                    cout << endl;
                }
                else {
                    cout << "This datastructure does not support the method called" << endl;
                };
            }

            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }


        //must specify DSname to able to move ptr --> (nextnode [dll_DSname] [ptr name]).Disclaimer: Ptr must have had to be made by calling ptrstart.
        else if (word1 == "nextnode") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                if (DS[word2]->gettype() == "dll") {
                    DLLpointer[word3] = DS[word2]->DLLmovePointerForward(DLLpointer[word3]);
                }

                else if (DS[word2]->gettype() == "sll") {
                    SLLpointer[word3] = DS[word2]->SLLmovePointerForward(SLLpointer[word3]);
                    
                }
                else {
                    cout << "This datastructure does not support the method called" << endl;
                };
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }



        //is end of the list. syntax --> isend [DSName] [PTR Name] Disclaimer: Ptr must have had to be made by calling ptrstart.
        else if (word1 == "isend") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                if (DS[word2]->gettype() == "dll") {
                    if (DS[word2]->DLLatEndOfList(DLLpointer[word3])) {
                        cout << "Pointer is at the end of the list!" << endl;
                    }
                    else cout << "Pointer is not at the end of the list!" << endl;
                    ;
                }
                else if (DS[word2]->gettype() == "sll") {
                    if (DS[word2]->SLLatEndOfList(SLLpointer[word3])) {
                        cout << "Pointer is at the end of the list!" << endl;
                    }
                    cout << "Pointer is not at the end of the list!" << endl;
                }
                else {
                    cout << "This datastructure does not support the method called" << endl;
                };
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }




        else if (word1 == "ishead") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                if (DS[word2]->gettype() == "dll") {
                    if (DS[word2]->DLLatHeadOfList(DLLpointer[word3])) {
                        cout << "Pointer is at the head of the list!" << endl;
                        DLLisend = true;
                    }

                    else cout << "Pointer is not at the head of the list!" << endl; DLLishead = false;
                    ;
                }
                else if (DS[word2]->gettype() == "sll") {
                    if (DS[word2]->SLLatHeadOfList(SLLpointer[word3])) {
                        cout << "Pointer is at the head of the list!" << endl;
                    }
                    cout << "Pointer is not at the head of the list!" << endl;
                }
                else {
                    cout << "This datastructure does not support the method called" << endl;
                };
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }


        //--------------------------------------Methods for Queue & Stack:

        else if (word1 == "push") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                num = stod(word3);
                if (DS[word2]->gettype() == "queue") {
                    DS[word2]->Queuepush(num);
                }
                else if (DS[word2]->gettype() == "stack") {
                    DS[word2]->Stackpush(num);
                }
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }

        else if (word1 == "pop") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                if (DS[word2]->gettype() == "queue") {
                    DS[word2]->Queuepop();
                }
                else if (DS[word2]->gettype() == "stack") {
                    DS[word2]->Stackpop();
                }
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }

        else if (word1 == "front") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                cout << DS[word2]->Queuefront() << endl;
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }

        else if (word1 == "back") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                cout << DS[word2]->Queueback() << endl;
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }



        else if (word1 == "top") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                cout << DS[word2]->Stacktop() << endl;
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }



        else if (word1 == "isfull") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                if (DS[word2]->gettype() == "queue") {
                    if (DS[word2]->QueueisFull()) {
                        cout << "Queue is full!" << endl;
                    }
                    cout << "Queue is not full!" << endl;
                }
                if (DS[word2]->gettype() == "stack") {
                    if (DS[word2]->StackisFull()) {
                        cout << "Stack is full!" << endl;
                    }
                    else cout << "Stack is not full!" << endl;
                }
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }




        else if (word1 == "isempty") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                if (DS[word2]->gettype() == "queue") {
                    if (DS[word2]->QueueisEmpty()) {
                        cout << "Queue is empty!" << endl;
                    }
                    else cout << "Queue is not empty!" << endl;
                }
                if (DS[word2]->gettype() == "stack") {
                    if (DS[word2]->StackisEmpty()) {
                        cout << "Stack is empty!" << endl;
                    }
                    else cout << "Stack is not empty!" << endl;
                }
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }


        //--------------------------------------Methods for BST

        else if (word1 == "insert") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                num = stod(word3);
                DS[word2]->BSTaddItem(num);
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }

        //deleteitem from BST
        else if (word1 == "deleteitem") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                num = stod(word3);
                DS[word2]->BSTdeleteItem(num);
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }

        else if (word1 == "root") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                cout << DS[word2]->BSTgetRoot()->data << endl; //returns BSTNode pointer and uses that pointer to retrieve the attribute data(which is the value stored in the node)
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }

        else if (word1 == "postorder") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                DS[word2]->BSTpostorder(DS[word2]->BSTgetRoot());
                cout << endl;
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }

        else if (word1 == "preorder") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                DS[word2]->BSTpreorder(DS[word2]->BSTgetRoot());
                cout << endl;
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }

        else if (word1 == "inorder") {
            if (DS.count(word2) == 0) {
                cout << "Error: The key " << word2 << " is not found in the map" << endl;
                continue;
            }
            try {
                DS[word2]->BSTinorder(DS[word2]->BSTgetRoot());
                cout << endl;
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unknown error occurred" << endl;
            }
        }
    }
}

