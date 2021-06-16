#include "univeristy.hpp"

#include "student.hpp"

University::University(const Student& s) {
    university_.push_back(s);
}
University::~University() {}

void University::dispalayBase() {
    for (const auto& student : univercity_) {
        std::cout << student -> getName() << ", "
                  << student -> getSurname() << ", "
                  << student -> getAdress() << ", "
                  << student -> getIndex() << ", "
                  << student -> getPesel() << ", "
                  << student -> getGender() << '\n';
    }
}

Student* University::findBySurname(const std::string& surname){
    auto isTheSame = [](Student* student){ return student -> getSurname() == surname; };
    auto result = std::find_if(university_.begin(), university_.end(), isTheSame);

    if (result == university.end()) {
        std::cout << "There is no such student in our database with given surname" << '\n';
        return nullptr;//nie wiem ??
    }

    return result;
}

Student* University::findByPesel(const long long& pesel){
    auto isTheSame = [](Student* student){ return student -> getPesel() == pesel; };
    auto result = std::find_if(university_.begin(), university_.end(), isTheSame);
   
    if (result == university.end()) {
        std::cout << "There is no such student in our database with given PESEL number" << '\n';
        return nullptr;//nie wiem co tutaj ??
    }
   
    return result;
}
   
// Implemented sort by pesel
void University::sortByPesel() {
    std::sort(university_.begin(), university_.end(),
              [](const Student& lhsPtr, const Student& rhsPtr) {
                  return lhsPtr -> getPesel() < rhsPtr -> getPesel();
              });
}
// Implemented sort by LName
void University::sortbyLname() {
    std::sort(university_.begin(), university_.end(),
              [](const Student& lhsPtr, const Student& rhsPtr) {
                  return lhsPtr -> getLname() < rhsPtr -> getLname();
              });
}
