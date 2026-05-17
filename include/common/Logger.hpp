#pragma once
#include <vector>
#include <string>

class Logger {
    static std::vector<std::string> messages;
    
public:
    static void log(const std::string& message);
    static const std::vector<std::string>& getMessages();
    static void clear();

};