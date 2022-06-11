#include "String.h"
#include <cstring>
#include <exception>

const int SIZE = 1024;

void MyString::copyFrom(const MyString &other) {
    size = other.size;
    str = new char[size + 1];
    strcpy(str, other.str);
}

void MyString::free() {
    delete[] str;
}


MyString::MyString() {
    str = new char[1];
    str[0] = '\0';
    size = 0;
}

MyString::MyString(const char *inputStr) {
    size = strlen(inputStr);
    str = new char[size + 1];
    strcpy(str, inputStr);
}

MyString::MyString(const MyString &other) {
    copyFrom(other);
}

MyString &MyString::operator=(const MyString &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

MyString::~MyString() {
    free();
}

size_t MyString::getSize() const {
    return size;
}

void MyString::concat(const MyString &other) {
    size = size + other.size;
    char *temp = new char[size + 1];
    strcpy(temp, str);
    strcat(temp, other.str);

    free();
    str = temp;
}

const char *MyString::c_str() const {
    return str;
}

MyString &MyString::operator+=(const MyString &other) {
    concat(other);
    return *this;
}

char &MyString::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("out of range");
    }
    return str[index];
}

char MyString::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("out of range");
    }
    return str[index];
}

MyString::MyString(MyString &&other) {
    str = other.str;
    other.str = nullptr;
    size = other.size;
}

MyString &MyString::operator=(MyString &&other) {
    if (this != &other) {
        free();
        str = other.str;
        other.str = nullptr;
        size = other.size;
    }
    return *this;
}

Vector<MyString> MyString::split(char s) const {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (str[i] == s)
            ++count;
    }
    Vector<MyString> list;
    int strIndex = 0;

    while (str[strIndex] != '\0') {
        char current[SIZE];
        int i = 0;
        while (str[strIndex] != s && str[strIndex] != '\0') {
            current[i++] = str[strIndex++];
        }
        current[i] = '\0';
        MyString currentStr(current);
        list.push_back(currentStr);
        if (str[strIndex] == '\0')
            break;
        ++strIndex;
    }
    return list;
}

double MyString::parseDouble() const {
    return atof(str);
}

int MyString::parseInt() const {
    return atoi(str);
}


std::ostream &operator<<(std::ostream &outFile, const MyString &newStr) {
    outFile << newStr.str;
    return outFile;
}

std::istream &operator>>(std::istream &inFile, MyString &myStr) {
    char data[SIZE];
    inFile.getline(data, SIZE);

    delete[] myStr.str;
    myStr.size = strlen(data);
    myStr.str = new char[myStr.size + 1];
    strcpy(myStr.str, data);
    return inFile;
}

std::ostream &operator>>(const MyString &myStr, std::ostream &outFile) {
    outFile.write((const char *) &myStr.size, sizeof(myStr.size));
    outFile.write(myStr.str, myStr.size);
    return outFile;
}

std::istream &operator<<(MyString &myStr, std::istream &inFile) {
    inFile.read((char *) &myStr.size, sizeof(myStr.size));
    myStr.str = new char[myStr.size + 1];
    inFile.read(myStr.str, myStr.size);
    myStr.str[myStr.size] = '\0';
    return inFile;
}

MyString operator+(const MyString &lhs, const MyString &rhs) {
    MyString temp(lhs);
    temp += rhs;
    return temp;
}

bool operator==(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator<=(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator<(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}