#include"exceptions.h"

int main() {
    wstring input; 
    wcout << L"Enter a string representing a number: "; 
    getline(wcin, input); 

    StringToIntConverter converter;

    try {
        int result = converter.convert(input);
       wcout << L"Computed value: " << result << endl; 
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}