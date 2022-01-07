#include <vector>
#include <iostream>
#include <fstream>

#include "app.hpp"

void Application::init() {
    if (!cfg.init()) {
        throw "error initializing config";
    }
}

void Application::addTodo() {
    std::cout << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << "                  ADD TODO               " << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << "Enter new TODO: ";
    
    std::string line;
    getline(std::cin, line);

    todos.push_back(line);
}

void Application::updateTodo() {
    std::cout << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << "                UPDATE TODO              " << std::endl;
    std::cout << "*****************************************" << std::endl;
    
    int id;
    while (1) {
        std::cout << "Enter TODO id: ";
        std::cin >> id;
        std::cin.ignore();
        id--;

        if (id < 0 || id >= todos.size()) {
            std::cout << "Incorrect TODO id, try again" << std::endl;
            continue;
        }

        break;
    }

    std::cout << "Enter new TODO: ";
    std::string line;
    getline(std::cin, line);

    todos[id] = Todo{line};
    std::cout << "TODO updated!" << std::endl;
}

void Application::deleteTodo() {
    std::cout << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << "                DELETE TODO              " << std::endl;
    std::cout << "*****************************************" << std::endl;
    
    int i;
    while (1) {
        std::cout << "Enter TODO id: ";
        std::cin >> i;
        std::cin.ignore();
        i--;

        if (i < 0 || i >= todos.size()) {
            std::cout << "Incorrect TODO id, try again" << std::endl;
            continue;
        }

        break;
    }

    todos.erase(todos.begin() + i);
    std::cout << "TODO deleted!" << std::endl;
}

void Application::loadTodos() {
    std::cout << "Attempting to read file " << cfg.getLoadFile() << std::endl;
    std::ifstream file{cfg.getLoadFile(), std::ios_base::in};
    if (!file) {
        perror("unable to open file for reading");
        return;
    }

    std::string line;
    todos.clear();
    while (getline(file, line)) {
        Todo t = codec.decode(line);
        todos.push_back(t);
    }

    std::cout << "File loaded!" << std::endl;
}

void Application::saveTodos() {
    std::cout << "Attempting to save to " << cfg.getSaveFile() << std::endl;
    std::ofstream file{cfg.getSaveFile(), std::ios_base::out};
    if (!file) {
        perror("unable to open file for saving");
        return;
    }

    for (Todo &t: todos) {
        file << codec.encode(t) << '\n';
    }

    std::cout << "File saved!" << std::endl;
}

void Application::exitApp() {
    std::cout << "Thank you for using our app!" << std::endl;
    exit(EXIT_SUCCESS);
}

void Application::render() {
    int choice;
    std::cout << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << "                  TODO LIST              " << std::endl;
    std::cout << "*****************************************" << std::endl;

    print();

    std::cout << std::endl;
    std::cout << "Commands:" << std::endl;
    std::cout << "    1. Add TODO" << std::endl;
    std::cout << "    2. Update TODO" << std::endl;
    std::cout << "    3. Delete TODO" << std::endl;
    std::cout << "    4. Load TODOs from file" << std::endl;
    std::cout << "    5. Save & Exit" << std::endl;
    std::cout << "Enter command: ";

    std::cin >> choice;
    std::cin.ignore();
    switch (choice) {
        case 1:
            addTodo();
            break;
        
        case 2:
            updateTodo();
            break;
        
        case 3:
            deleteTodo();
            break;

        case 4:
            loadTodos();
            break;

        case 5:
            saveTodos();
            exitApp();

        default:
            std::cout << "Incorrect input, please try again" << std::endl;
            break;
    }
}

void Application::print() {
    for (Todo &t: todos) {
        std::cout << " * " << t.toString() << std::endl;
    }
}