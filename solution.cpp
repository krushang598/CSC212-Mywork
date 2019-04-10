// implement the is balanced function, and add a test for it in main
#include <queue>
#include <stack>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cctype>
#include <algorithm>
#include <string>
#include <fstream>

bool isNotAlnum(char c) {
    return isalnum(c) == 0;
}

bool ispalindromeQueue(std::queue <std::string> text)
{
    std::queue <std::string> reverse2, copy1, copy2;
    std::string line;

    while(!text.empty())
    {
        line = text.front();
        copy1.push(line);
        copy2.push(line);
        text.pop();
    }

    while(!copy1.empty())
    {
        line = text.front();
        reverse2.push(line);
        copy1.pop();
    }

    assert(reverse2.size()==copy2.size());
    
    while(!reverse2.empty()){
        if(reverse2.front()!=copy2.front()){
            return false;
        }
        reverse2.pop();
        copy2.pop();
    }  
    return true;
}

bool ispalindromeStack(std::stack <std::string> text)
{
    std::stack <std::string> reverse2, copy1, copy2;
    std::string line;

    while(!text.empty())
    {
        line = text.top();
        copy1.push(line);
        copy2.push(line);
        text.pop();
    }

    while(!copy1.empty())
    {
        line = text.top();
        reverse2.push(line);
        copy1.pop();
    }

    assert(reverse2.size()==copy2.size());
    
    while(!reverse2.empty()){
        if(reverse2.top()!=copy2.top()){
            return false;
        }
        reverse2.pop();
        copy2.pop();
    }  
    return true;
}

int main()
{

    std::stack <std::string> reverse;
    std::queue <std::string> forward;
    std::string filename;

    std::cout << "which file do you want to open?";
    getline(std::cin, filename);

    while(filename != "quit")
    {
        std::ifstream test_data(filename);
        if(!test_data)
        {
            throw::std::runtime_error("Can't find test file;");
        }
        std::string line;
        while(getline(test_data, line))
        {
            // load into data structure
            line.erase(std::remove_if(line.begin(), line.end(), isNotAlnum), line.end());
            reverse.push(line);
            forward.push(line);
        }    
        
        test_data.close();

        assert(reverse.size()==forward.size());
        if(reverse.empty())
        {
            std::cout<<"The file you entered is empty. "
            continue;
        }

        std::cout<<"Checking using Stack: "<<ispalindromeStack(reverse)<<"\n";
        std::cout<<"Checking using Queue: "<<ispalindromeQueue(forward)<<"\n";

        std::cout << "which file do you want to open?";
        getline(std::cin, filename);
    }
}