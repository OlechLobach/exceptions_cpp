#ifndef exceptions_h
#define exceptions_h
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <locale> 
using namespace std;

class StringToIntConverter {
public:
    int convert(const wstring& str) { 
        wstring modifiedStr;

        for (wchar_t c : str) { 
            if (isdigit(c) || (c == L'-' && modifiedStr.empty())) { 
                modifiedStr.push_back(c);
            }
        }

        if (modifiedStr.empty()) {
            throw invalid_argument("No digits found.");
        }

        try {
            int value = stoi(modifiedStr);
            return value;
        }
        catch (const out_of_range& e) {
            cerr << "Error: Out of range of int.\n";
            throw;
        }
        catch (const invalid_argument& e) {
            cerr << "Error: Invalid number format.\n";
            throw;
        }
    }
};

#endif