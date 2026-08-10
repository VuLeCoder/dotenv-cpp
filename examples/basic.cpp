#include <env.h>

#include <cstdlib>
#include <iostream>

int main() {
    Env dotenv;

    if(!dotenv.load("examples/.env")) {
        std::cerr << "Failed to load .env\n";
        return 1;
    }

    const std::string NAME = "NAME";
    std::cout << dotenv.get(NAME) << std::endl;

    return 0;
}
