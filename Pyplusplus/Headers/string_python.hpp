#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


namespace python
{

    class pystr
    {
    private:
       std::string string_to_operate;
       std::vector<std::string> splitted;
       int is_deleted;
       int is_splitted;
    public:
        pystr();
        pystr(std::string);
        ~pystr();
        void split(const char*);
        void display_split();
        void display_str();
        void mem_free();
        void erase_element_splitted(std::vector<std::string>::iterator);
        int index_of_split(std::string);
        std::string front_split();
        std::string last_split();
        std::string join(char*);
        std::vector<std::string> return_splitted();
        std::vector<std::string>::iterator find_split_iterator(std::string);

        //Operators
        bool operator==(pystr&) const;
        pystr operator+(pystr&);


    };
}
