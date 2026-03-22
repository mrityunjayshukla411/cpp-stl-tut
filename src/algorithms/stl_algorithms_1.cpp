#include<iostream>
#include<algorithm>
#include <random>
#include<print>
#include<string>
#include<vector>



int main()
{
    std::random_device rd;              // seed
    std::mt19937 gen(rd());             // Mersenne Twister engine
    std::uniform_int_distribution<> dist(1, 1000); // range: 1–100

    size_t n = 10;
    std::vector<int> v(10);

    for (size_t i = 0; i < n; i++)
    {
        v[i] = dist(gen);
    }

    std::println("====\tDefault sort\t====");
    
    std::println("Unsorted Vector: {}",v);
    
    sort(v.begin(),v.end());
    
    std::println("Sorted Vector: {}",v);
    
    std::println("====\tShuffling vector\t====");
    
    std::shuffle(v.begin(),v.end(),gen);
    
    std::println("Shuffled Vector: {}",v);
    
    std::println("====\tMixed sort (even before odd)\t====");
    
    std::sort(v.begin(),v.end(),[](int x, int y){
        return x%2 < y%2;
    });
    
    
    std::println("Mixed Vector: {}",v);
    
    std::println("====\tMixed sort (descending)\t====");
    int polarity = -1;
    
    std::sort(v.begin(),v.end(),[](int x, int y){
        return polarity*x < y*polarity;
    });
    
    std::println("Mixed Vector: {}",v);
    
    std::println("====\t Transforming vector (odd-even)\t====");
    
    
    std::vector<int> v2(v.size());
    
    std::transform(v.begin(),v.end(),v2.begin(),[](int x){
        return x%2;
    });
    
    std::println("Original Vector: {}",v);
    std::println("Transformed Vector: {}",v2);

    std::println("====\t Transforming string (casing)\t====");
    
    
    std::string s1= "PaNdUrAnGa";
    std::string s2(s1.size(),'x');
    
    std::transform(s1.begin(),s1.end(),s2.begin(),[](char x){
        if(tolower(x) - x > 0)
        {
            return tolower(x);
        }
        return toupper(x);
    });
    
    std::println("Original string: {}",s1);
    std::println("Transformed string: {}",s2);


    return 0;
}