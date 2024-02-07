#include"exceptions.h"

int main() {
    try {
        double result = divide(10.0, 0.0);
        cout << "Result: " << result << endl; 
    }
    catch (const MathException& e) {
        cerr << e.what() << endl;
    }
    try {
       
        processFile("example.txt");
    }
    catch (const FileNotFoundException& e) {
        cerr << e.what() << endl;
    }
    catch (const AccessDeniedException& e) {
        cerr << e.what() << endl;
    }

  
    try {
       
        int* ptr = new int[1000000000]; 
        if (!ptr) {
            throw MemoryException();
        }
    }
    catch (const MemoryException& e) {
        cerr << e.what() << endl;
    }
    catch (const InvalidArgumentException& e) {
        cerr << e.what() << endl;
    }

    return 0;
}