#pragma once

#include <array>
#include <iostream>
#include <functional>
#include <utility>
#include <stdio.h>
#include <string>

#include "Command.hpp"
#include "University.hpp"

class Remove : public Command {
public:
    Remove() = default;

    void operator()(University& university) override{
        std::cout <<"......................................................................................\n";
        getName();
        std::cout << '\n';
        int option{};

        std::array<std::pair<std::string, std::function<void()>>, 3> removeOptions {{
        {"1-remove-by-Pesel", [&](){ std::string pesel{};
                                     std:: cout << "Give the pesel :";
                                     std::cin >> pesel;
                                     //university.removeByPesel(pesel);
                                     return;
                                     }},
        {"2-remove-by-IndexNumeber", [&](){ size_t indexNr{};
                                            std:: cout << "Give the Index Numer:";
                                            std::cin >> indexNr;
                                            university.removeByIndexNumber(indexNr);
                                            return;}},
        {"3-back-to-main-menu", [&](){ do {
                                            std::cout << "\nDo you want to back to main-menu ( y/n ):  ";
                                            char c;
                                            std::cin >> c;
                                            if ( c == 'n') { option += 1;
                                                             break; }
                                            if ( c == 'y') { break; }
                                        } while (true);
                                        return;
                                     }}
        }};

        while (true){
            std::cout << "Remove options : \n";
            for (const auto& [key, value] : removeOptions) {
                std::cout << key << '\n';
            }
            std::cout << "\nyour choice (number) : ";
            try {
                std::cin >> option;
                auto remove = removeOptions.at(option-1).second;
                remove();
            } catch(...) {
                std::cout << "Invalid input\n";
            }

            if (option == removeOptions.size()) {
                break;
            }
            option = -1;
        }
    }

    void getName() const override {
        std::cout << "Remove\n";
    }
};
