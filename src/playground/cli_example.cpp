#include <CLI/CLI.hpp>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    CLI::App app{"Simple CLI11 example"};

    // Options / flags
    std::string name = "world";
    int repeat = 1;
    bool excited = false;

    app.add_option("-n,--name", name, "Name to greet");
    app.add_option("-r,--repeat", repeat, "Number of times")->check(CLI::PositiveNumber);
    app.add_flag("-e,--excited", excited, "Add excitement");

    CLI11_PARSE(app, argc, argv);

    // Logic
    for (int i = 0; i < repeat; ++i) {
        std::cout << "Hello, " << name;
        if (excited) std::cout << "!!!";
        std::cout << "\n";
    }

    return 0;
}