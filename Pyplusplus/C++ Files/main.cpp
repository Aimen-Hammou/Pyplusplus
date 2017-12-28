#include "string_python.hpp"

int main()
{
    python::pystr str("Hello-my-name-is-Aimen");
    python::pystr str2("Hello-my-name-is-Aimen");
    python::pystr str3;
    str3 = str + str2;
    str3.split("-");
    if (str == str2) std::cout << "Are equal " << std::endl;
    else std::cout << "Are not equal" << std::endl;
    //str.display_str(); //WORKS FINE
    str.split("-");
    std::string joined = str.join("-");
    //str.erase_element_splitted(str.find_split_iterator("name"));
    int index = str.index_of_split("name");
    auto front = str.front_split();
    auto back = str.last_split();
    std::cout << index << std::endl;
    str.display_split();
    str.mem_free();
//    str3.display_split();
//    str3.display_str();
    return 0;
}
