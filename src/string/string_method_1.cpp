#include <string>
#include <cstdint>
#include <print>

int main()
{
    std::string base_str = "Pandu will become the greatest film director the world has ever seen";
    
    std::println("Base string: {}",base_str);
    
    for (std::size_t i = 0; i < base_str.length(); i++)
    {
        std::println("length: {}\tsubstr: {}\n",i,base_str.substr(i,i));
    }

    std::string str_to_find = "the";

    size_t found = base_str.find(str_to_find);
    if (found != std::string::npos)
    {
        std::println("Found {} at pos {}",str_to_find,found);
    }
   
    char *str_data = base_str.data();
    std::println("Char array{}",str_data);

    for(int i = 1 ; i < 20 ; i+=2)
    {
        base_str.erase(base_str.begin() + i);
        std::println("Base str: {}\n",base_str);
    }
    
    base_str.replace(20,10,"pa--pp--u",2,6);
    std::println("Replaced Base str: {}\n",base_str);

    return 0;
}
