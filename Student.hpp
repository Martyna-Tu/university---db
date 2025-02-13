#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Person.hpp"

class Student : public Person {
private:
    size_t indexNumber_{0};

public:
    void setIndex(const size_t);

    size_t getIndex() const;

    Student() = default;
    Student(std::string name, std::string surname, std::string address, std::string pesel, std::string gender, size_t indexNumber);
    ~Student();
};
