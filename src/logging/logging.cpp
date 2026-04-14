#include<print>
#include<vector>

int main()
{
    std::vector<int> v;
    uint64_t x = 69;
    for (size_t i = 0; i < 1024*1024; i++)
    {
        v.push_back(i);
    }
    
    std::println("x = {:#^20}",x);
    std::println("Vector size = {:#^20}",v.size());
    std::println("Vector capacity = {:#^20}",v.capacity());
    v.pop_back();
    std::println("Vector size = {:#^20}",v.size());
    std::println("Vector capacity = {:#^20}",v.capacity());
    v.resize(10);
    std::println("Vector size = {:#^20}",v.size());
    std::println("Vector capacity = {:#^20}",v.capacity());
    v.shrink_to_fit();
    std::println("Vector size = {:#^20}",v.size());
    std::println("Vector capacity = {:#^20}",v.capacity());
    return 0;
}