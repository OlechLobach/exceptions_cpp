#ifndef exceptions_h
#define exceptions_h
#include <iostream>
#include <exception>
#include <string>
using namespace std;

class MemoryException : public exception {
public:
    virtual const char* what() const noexcept override {
        return "Memory Exception: Unable to allocate memory.";
    }
};

class MathException : public exception {
private:
    string errorMessage;

public:
    MathException(const string& message) : errorMessage(message) {}

    virtual const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};

class FileException : public exception {
private:
    string fileName;

public:
    FileException(const string& filename) : fileName(filename) {}

    virtual const char* what() const noexcept override {
        return ("File Exception: Error while processing file '" + fileName + "'").c_str();
    }
};

class InvalidArgumentException : public exception {
public:
    virtual const char* what() const noexcept override {
        return "Invalid Argument Exception: Invalid argument passed to function.";
    }
};

class FileNotFoundException : public exception {
private:
    string fileName;

public:
    FileNotFoundException(const string& filename) : fileName(filename) {}

    virtual const char* what() const noexcept override {
        return ("File Not Found Exception: File '" + fileName + "' not found.").c_str();
    }
};

class AccessDeniedException : public exception {
private:
    string fileName;

public:
    AccessDeniedException(const string& filename) : fileName(filename) {}

    virtual const char* what() const noexcept override {
        return ("Access Denied Exception: Access to the file '" + fileName + "' is denied.").c_str();
    }
};

double divide(double dividend, double divisor) {
    if (divisor == 0) {
        throw MathException("Math Exception: Division by zero.");
    }
    return dividend / divisor;
}


void processFile(const std::string& filename) {
        throw FileNotFoundException(filename);

    throw AccessDeniedException(filename);
}
#endif