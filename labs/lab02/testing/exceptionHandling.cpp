#include <iostream>

using namespace std;

class Exception {
    string message;
public:
    Exception(string msg) : message(msg) {}
    string getMessage() { 
        return message;
    }
};

class IndexOutOfBoundsException : public Exception {
public:
    IndexOutOfBoundsException(string msg) : Exception(msg) {}
};

int badFunction(int errtype) {
    switch(errtype) {
        case 0:
            throw 5;
        case 1:
            throw 3.5f;
        case 2:
            throw string("FAILURE");
        case 3:
            throw Exception("Critical Failure!");
        case 4:
            throw IndexOutOfBoundsException("Index off the end of array");
    };
    return 0;
}

int main(int arg, char const *argv[])
{
    try {
        badFunction(2);
    }  
    catch(int ex) {
        cout << "Int error caught " << ex << endl;   
    }
    catch(float ex) {
        cout << "Float error caught " << ex << endl;   
    }
    catch(string ex) {
        cout << "String error caught " << ex << endl;
    }
    catch(IndexOutOfBoundsException ex) {
        cout << ex.getMessage() << endl;
    }
    catch(Exception ex) {
        cout << ex.getMessage() << endl;
    }
    catch(...) {
        cout << "An error occurred" << endl;
    }
    
    return 0;
}