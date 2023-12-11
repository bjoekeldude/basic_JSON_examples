#include "json.hpp"
#include <iostream>
#include <fstream>


namespace meineFunktionen{

    void print_car_json(const nlohmann::json& car){
            std::cout << car["vin"] << std::endl;
            std::cout << car["manufacturer"] << std::endl;
            std::cout << car["model"] << std::endl;
    };

}


int main(int argc, char** argv){

    std::ifstream inputfile{argv[1]};
    nlohmann::json carDB{nlohmann::json::parse(inputfile)};


    for (auto& car : carDB["cars"]){
        meineFunktionen::print_car_json(car);
    }
}
