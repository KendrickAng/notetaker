#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <unordered_map>
#include <iostream>
#include <fstream>

#define KEY_SAVEFILE "save"
#define KEY_LOADFILE "load"

class Config {
private:
    std::unordered_map<std::string, std::string> cfg;
public:
    bool init() {
        // parse config file
        std::ifstream file{"config.txt"};
        if (!file) {
            perror("error reading config file");
            return false;
        }

        std::string line;
        while (getline(file, line)) {
            std::string key = line.substr(0, line.find("="));
            std::string val = line.substr(line.find("=")+1);
            std::cout << "key " << key << std::endl;
            std::cout << "val " << val << std::endl;
            cfg[key] = val;
        }

        return true;
    }

    std::string getLoadFile() {
        if (cfg.find(KEY_LOADFILE) != cfg.end()) {
            return cfg[KEY_LOADFILE];
        }
        return "";
    }

    std::string getSaveFile() {
        if (cfg.find(KEY_SAVEFILE) != cfg.end()) {
            return cfg[KEY_SAVEFILE];
        }
        return "";
    }
};

#endif