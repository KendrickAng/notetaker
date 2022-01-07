#include <string>

#include "todo.hpp"

Todo::Todo() = default;
Todo::Todo(std::string content, Status status): content{content}, status{status} {}

Status Todo::getStatus() {
    return status;
}

std::string Todo::getContent() {
    return content;
}

std::string Todo::toString() {
    std::string prefix = (status == Status::DONE) ? "[X]" : "[ ]";
    return prefix + " " + content;
}