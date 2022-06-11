#ifndef KINDLE_STRING_H
#define KINDLE_STRING_H

#include <iostream>
#include <fstream>
#include "Vector.hpp"

class MyString {
    char *str;
    size_t size;

    void copyFrom(const MyString &);
    void free();

    void concat(const MyString &);

public:
    MyString();

    MyString(const char *);
    //MyString(char *&);
    MyString(const MyString &);
    MyString &operator=(const MyString &);
    ~MyString();

    MyString(MyString &&);
    MyString &operator=(MyString &&);

    size_t getSize() const;
    const char *c_str() const;

    MyString& operator+=(const MyString &);
    char &operator[](size_t);
    char operator[](size_t) const;

    Vector<MyString> split(char) const;
    double parseDouble() const;
    int parseInt() const;

    friend std::ostream &operator<<(std::ostream &, const MyString &);
    friend std::istream &operator>>(std::istream &, MyString &);

    friend std::ostream &operator>>(const MyString &, std::ostream &);
    friend std::istream &operator<<(MyString &, std::istream &);

};

MyString operator+(const MyString &, const MyString &);

bool operator==(const MyString &, const MyString &);
bool operator<=(const MyString &, const MyString &);
bool operator<(const MyString &, const MyString &);


#endif //KINDLE_STRING_H
