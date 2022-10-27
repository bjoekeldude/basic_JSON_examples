#include <iostream>
#include <fstream>
#include <sstream>

struct myType_t{
    int a;
    int b;

    std::stringstream serialize(){
        std::stringstream retval;  
        retval << "{\"a\":" << a << ", \"b\": " << b <<"}";
        return retval;
    }
};




int main(int argc, char** argv){
    std::ofstream outputfile(argv[1]);
    if (!outputfile) std::abort;
    
    myType_t alpha{
        .a{1},
        .b{2}
    };

    std::stringstream out = alpha.serialize();

    std::cout << out.str();

    
    outputfile << alpha.serialize().str();
    outputfile.flush();
    outputfile.close();
}