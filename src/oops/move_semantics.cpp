#include<print>
#include<vector>
#include<string>
#include <utility> // for std::move
#include <chrono> // time

void print_rvalue(std::string&& str)
{
    std::string local = std::move(str);
    std::println("{:-^24}",std::move(str));
}

int main()
{
    std::string str = "pandu";
    std::println("string size {}",str.size());
    print_rvalue(std::move(str));
    std::println("string size {}",str.size());
    return 0;
}