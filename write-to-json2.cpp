#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

struct myType_t{
    int a;
    int b;

    nlohmann::json serialize(){
        nlohmann::json retval;

        retval["a"] = a;
        retval["b"] = b;

        return retval;
    };
};


int main(int argc, char** argv){

    myType_t beta{
        .a{10},
        .b{30}
    };

    nlohmann::json output = beta.serialize();

    std::ofstream out(argv[1]);

    out << output;
    out.flush();
    out.close();
}

