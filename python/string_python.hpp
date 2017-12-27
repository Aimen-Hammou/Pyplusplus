#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <vector>

namespace python
{

    class pystr
    {
    private:
       std::string string_to_operate;
       std::vector<std::string> splitted;
       int is_deleted;
    public:
        pystr();
        pystr(std::string);
        ~pystr();
        void mem_free();
        std::string  join(char*);
        void split(const char*);
        void display_split();
        void display_str();

    };
}
