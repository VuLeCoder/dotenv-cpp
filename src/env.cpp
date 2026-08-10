#include "env.h"
#include <fstream>

bool Env::load(const std::string& path) {
    std::ifstream file(path);
    if(!file)
        return false;

    std::string line;

    while(std::getline(file, line)) {
        if(line.empty() || line[0] == '#')
            continue;

        auto pos = line.find('=');
        if(pos == std::string::npos)
            continue;

        auto key = line.substr(0, pos);
        auto value = line.substr(pos + 1);

        data_[key] = value;
    }

    return true;
}

std::string Env::get(const std::string& key) const {
    auto it = data_.find(key);

    if(it == data_.end())
        return "";

    return it->second;
}
