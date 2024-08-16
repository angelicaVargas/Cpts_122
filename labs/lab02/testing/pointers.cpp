#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Student {

    string firstName;
    string lastName;

public:
    Student(string fname, string lname) : firstName(fname), lastName(lname) {}
    ~Student() {
        
       //default deconstructor that does nothing
    }

    string getFirstName() {

        return firstName;
    }

    string getLastName() {

        return lastName;
    }
};

//function to identify what is being created "factory function"
void createStudentObject(string fname, string lname, Student **s) { //**s is a pointer to another pointer "double pointer"

    (*s) = new Student(fname, lname); //dereference s to change the value that's stored

}

void staticVariable() {
    static int x = 1;

    cout << "Times called: " << x++ << endl;
}

void initializeArray(int size, int* array) {
    // for(int i =0; i < 100; i++) {
    //     array[i] = i; //less typing and does the same thing as the next?
    //     //using a numeric index to access an element of the array
    //     *(array + i) = i;  //need to get an address and dereference it
    // }
    int* temp = array;
    for(int i = 0; i < size; i++, temp++) {
        *temp = i; //entering an "array" address and going into the next integer
        //updating the array so it point to increments of the value
    }
}

void printArray(int size, int* array) { //pass in the size so you don't walk off the memory of the array
    for(int i = 0; i < size; i++) {
        cout << (i == 0 ? " " : ", ") << array[i];
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    
    int *x = new int[100]; //dynamically allocating int values
    int array[100]; //"array" is an identifier and gives us access to the chunk of memory

    cout << "&x: " << &x << endl;
    cout << "array: " << array << endl;    
    cout << "x: " << x << endl; //print out the value that is in "x"
    // this commant doesn't work::: find out why ::: cout << "printArray: " << printArray << endl;

    initializeArray(100, x); //can use this with statically allocated memory
    printArray(100, x);

    initializeArray(100, array); //can use this with dynamically allocated memory
    printArray(100, array);

    Student *p = new Student("John", "Doe");

    cout << "First Name: " << (p -> getFirstName()) << endl;
    cout << "Last Name: " << (p -> getLastName()) << endl;

    delete [] x; //specify the square brackets to delete everything

    cout << "x: " << x << endl; //print out the value that is in "x"

    x = new int[10]; //did not need 
    
    cout << "x: " << x << endl; //x is holding that value

    delete p; //to delete one thing (need to specify)

    createStudentObject("Jane", "Doe", &p); //need to pass address to have it stored

    cout << "First Name: " << (p -> getFirstName()) << endl;
    cout << "Last Name: " << (p -> getLastName()) << endl;

    delete p;
//if using malloc, use free. if using new, use delete

    for(int i = 0; i < 10; i++) {
        staticVariable();
    }
    return 0;
}
//don't mix and match "malloc" and "new"
