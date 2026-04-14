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
    
    std::sort(v.begin(),v.end(),[polarity](int x, int y){
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
    
    std::println("====\t Reversing a vector\t====");
    std::vector<int> vec(n);
    
    for (size_t i = 0; i < n; i++)
    {
        vec[i] = i;
    }
    
    std::println("Original vec: {:+^50}",vec);
    reverse(vec.begin() , vec.begin() + 5);
    std::println("Reversed vec: {:+^50}",vec);
    
    std::println("====\t Nth element in a vector\t====");
    
    auto print_vec = [](std::string_view label, const auto& v) {
        std::println("{:<40}{:+^80}", label, v);
    };
    
    print_vec("Original vec:", vec);
    nth_element(vec.begin(), vec.begin() + 5, vec.end());
    print_vec("Nth element in correct position vec:", vec);
    
    std::println("====\t Search vector in a vector\t====");
    sort(vec.begin(),vec.end());
    
    std::vector<int> sec = {4,5,6};
    std::vector<int>::iterator it =  search(vec.begin(),vec.end(),sec.begin(),sec.end());
    
    std::println("Original vec: {:_^50}",vec);
    std::println("Found at {}",*it);
    
    std::println("====\t Checking if number in a vector is even/odd\t====");
    std::println("Original vec: {:_^50}",vec);

    std::println("All elements are even {}",all_of(vec.begin(),vec.end(),[](int x){return (x*x)%2 == 0;}));
    std::println("Any element is even {}",any_of(vec.begin(),vec.end(),[](int x){return (x*x)%2 == 0;}));
    std::println("None of the elements are even {}",none_of(vec.begin(),vec.end(),[](int x){return (x*x)%2 == 0;}));
    
    std::println("====\t Get frequency of elements\t====");
    std::println("Original vec: {:_^50}",vec);

    std::println("Count of numbers whose square is even in vec {}",count_if(vec.begin(),vec.end(),[](int x){return (x*x)%2 == 0;}));
    std::println("Count of even numbers in vec {}",count_if(vec.begin(),vec.end(),[](int x){return x%2 == 0;}));

    return 0;
}