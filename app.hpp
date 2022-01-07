#ifndef TODOS_HPP
#define TODOS_HPP

#include <vector>

#include "todo.hpp"
#include "config.hpp"
#include "codec.hpp"

class Application {
private:
    std::vector<Todo> todos;
    Config cfg;
    Codec codec;

    void addTodo();
    void updateTodo();
    void deleteTodo();
    void loadTodos();
    void saveTodos();
    void exitApp();

public:
    void init();
    void render();
    void print();
};

#endif