#pragma once
#include <string>
#include <unordered_map>

class Env {
public:
    bool load(const std::string& path);
    std::string get(const std::string& key) const;

private:
    std::unordered_map<std::string, std::string> data_;
};
