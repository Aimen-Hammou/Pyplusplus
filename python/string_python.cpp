#include "string_python.hpp"

python::pystr::pystr()
{
    this->string_to_operate = "Empty string";
    this->is_deleted = 0;
}

python::pystr::pystr(std::string to_copy)
{
    this->string_to_operate = to_copy;
    this->is_deleted = 0;
}

python::pystr::~pystr()
{
    if (this->is_deleted == 0)
    {
    this->string_to_operate.clear();
    this->splitted.clear();
    }
}


void python::pystr::mem_free()
{
    this->string_to_operate.clear();
    this->splitted.clear();
    this->is_deleted = 1;
}

void python::pystr::display_str()
{
    std::cout << string_to_operate;
}

void python::pystr::split(const char* splitter)
{
    char* token = std::strtok(&string_to_operate[0], splitter);
    while (token != NULL)
    {
        splitted.push_back(std::string(token));
        token = std::strtok(NULL, splitter);
    }
}

std::string python::pystr::join(char* joiner)
{
    std::string return_joined("");
    for (std::vector<std::string>::size_type it = 0;
         it < this->splitted.size() - 1;
          it++)
    {
        return_joined += this->splitted[it];
        return_joined += std::string(joiner);
    }
    return_joined += this->splitted.back();
    return return_joined;
}

void python::pystr::display_split()
{
    std::cout << "[";
    for (std::vector<std::string>::size_type it = 0;
         it < this->splitted.size();
         it++)
        {
            if (this->splitted[it] == this->splitted.back())
                std::cout << "\"" << this->splitted[it] <<  "\"";
            else
                std::cout << "\"" << this->splitted[it] <<  "\"" << ", ";
        }
    std::cout << "]";
}
