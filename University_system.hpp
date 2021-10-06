#pragma once

#include "Command.hpp"
#include "University.hpp"

#include <map>

class University_system {
public:
    University_system() = default; 
    void run();
    void init();
    
private : 
    bool dbON_{};
    std::map<std::string, std::unique_ptr<Command>> commands_{};
    University university_{};
};
