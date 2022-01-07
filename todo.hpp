#ifndef TODO_HPP
#define TODO_HPP

#include <string>

enum class Status {
    DOING,
    DONE,
};

class Todo {
private:
    std::string content;
    Status status;

public:
    Todo();
    Todo(std::string content, Status s=Status::DOING);

    Status getStatus();
    std::string getContent();
    std::string toString();
};

#endif