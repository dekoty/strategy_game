#include "../../include/common/Logger.hpp"

std::vector<std::string> Logger::messages;

void Logger::log(const std::string& message) {
    messages.push_back(message);
}

const std::vector<std::string>& Logger::getMessages() {
    return messages;
}

void Logger::clear() {
    messages.clear();
}