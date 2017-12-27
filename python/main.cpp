#include "string_python.hpp"

int main()
{
    python::pystr str("Hello-my-name-is-Aimen");
    //str.display_str(); //WORKS FINE
    str.split("-");
    std::string joined = str.join("-");
    str.display_split();
    str.mem_free();
    return 0;
}
