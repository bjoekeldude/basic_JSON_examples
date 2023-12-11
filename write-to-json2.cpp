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
    std::ofstream outputfile{argv[1]};
    if (!outputfile) std::abort;
    
    myType_t beta{
        .a{10},
        .b{30}
    };

    nlohmann::json output{beta.serialize()};

    outputfile << output;
    outputfile.flush();
    outputfile.close();
}

