#include "string_python.hpp"

python::pystr::pystr()
{
    this->string_to_operate = "Empty string";
    this->is_deleted = 0;
    this->is_splitted = 0;
}

python::pystr::pystr(std::string to_copy)
{
    this->string_to_operate = to_copy;
    this->is_deleted = 0;
    this->is_splitted = 0;
}

python::pystr::~pystr()
{
    if (this->is_deleted == 0)
    {
    this->string_to_operate.clear();
    this->splitted.clear();
    }
}


void
python::pystr::mem_free()
{
    this->string_to_operate.clear();
    this->splitted.clear();
    this->is_deleted = 1;
    this->is_splitted = 0;
}

void
python::pystr::display_str()
{
    std::cout << string_to_operate << std::endl;
}

void
python::pystr::split(const char* splitter)
{
    this->is_splitted = 1;
    char* token = std::strtok(&string_to_operate[0], splitter);
    while (token != NULL)
    {
        splitted.push_back(std::string(token));
        token = std::strtok(NULL, splitter);
    }
}

std::string
python::pystr::join(char* joiner)
{
    if (this->is_splitted == 1)
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
    else
    {
        std::cout << "Error: need to split the string before calling \"join\"" << std::endl;
        return "";
    }

}

void
python::pystr::display_split()
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
    std::cout << "]" << std::endl;

}

std::vector<std::string> python::pystr::return_splitted()
{
    return this->splitted;
}


std::vector<std::string>::iterator
python::pystr::find_split_iterator(std::string element)
{
    if (this->is_splitted == 1)
    {
    //Could use ALGORITHM find function but I would rather make it by myself.
    for(std::vector<std::string>::iterator it = this->splitted.begin();
        it != this->splitted.end();
        ++it)
        {
            if (*it == element)
                return it;
        }
    }
    else
    {
        std::cout << "Error: need to split before calling \"find_split_iterator\"" << std::endl;
    }
}


void
python::pystr::erase_element_splitted(std::vector<std::string>::iterator it_to_elem)
{
    if(this->is_splitted == 1)
        this->splitted.erase(it_to_elem);
    else
        std::cout << "Error: need to split before calling \"find_split_iterator\"" << std::endl;
}



int
python::pystr::index_of_split(std::string element)
{
    if (this->is_splitted == 1)
    {
        if (std::find(this->splitted.begin(), this->splitted.end(), element) != this->splitted.end())
        {
#if _cplusplus > 199711L
        return this->find_split_iterator(element) - this->splitted.begin();
#else
        return std::distance(this->splitted.begin(), this->find_split_iterator(element));
#endif // _cplusplus
        }
        else
            return -1;
    }
    else
        std::cout << "Error: need to split before calling \"index_of_split\"" << std::endl;
    return -1;
}


std::string
python::pystr::front_split()
{
    if (this->is_splitted == 1)
        return this->splitted.front();
    else
        std::cout << "Error: need to split before calling \"front_split\"" << std::endl;
    return "";

}

std::string
python::pystr::last_split()
{
    if (this->is_splitted == 1)
        return this->splitted.back();
    else
        std::cout << "Error: need to split before calling \"last_split\"" << std::endl;
    return "";
}

bool
python::pystr::operator==(python::pystr& element) const
{
    if (!this->string_to_operate.compare(element.string_to_operate))
        return true;
    else
        return false;
}

python::pystr
python::pystr::operator+(python::pystr& element)
{
    python::pystr temp;
    temp.string_to_operate = this->string_to_operate +
                             element.string_to_operate;
    std::vector<std::string> temp_vec;
    temp_vec.insert(temp_vec.end(), this->splitted.begin(), this->splitted.end());
    temp_vec.insert(temp_vec.end(), element.splitted.begin(), element.splitted.end());
    temp.splitted = temp_vec;
    return temp;
}

























































