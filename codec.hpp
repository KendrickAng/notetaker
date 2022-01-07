#ifndef CODEC_HPP
#define CODEC_HPP

#include <string>
#include <sstream>

#include <todo.hpp>

class Codec {
private:
    int statusToInt(Status s) {
        switch (s) {
            case Status::DOING:
                return 0;
            case Status::DONE:
                return 1;
            default:
                throw "unknown TODO status";
        }
    }

    Status intToStatus(int s) {
        switch (s) {
            case 0:
                return Status::DOING;
            case 1:
                return Status::DONE;
            default:
                throw "unknown int for TODO status";
        }
    }

public:
    std::string encode(Todo &todo) {
        // convert enum status to an integer
        int status = statusToInt(todo.getStatus());
        return std::to_string(status) + " " + todo.getContent();
    }

    Todo decode(std::string &s) {
        std::stringstream ss(s);
        int tmp;
        std::string content;
        ss >> tmp >> content;
        ss.ignore();
        getline(ss, content);

        Status status = intToStatus(tmp);

        return Todo{content, status};
    }
};

#endif