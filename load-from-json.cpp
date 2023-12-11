#include "json.hpp"
#include <iostream>
#include <fstream>


namespace meineFunktionen{

    void print_car_json(const nlohmann::json& car){
        for(auto& key : car.items(){
            std::cout << "Key: " << element.key() << ", Value: " << element.value() << std::endl;
        }
    };

}


int main(int argc, char** argv){

    std::ifstream inputfile{argv[1]};
    nlohmann::json carDB{nlohmann::json::parse(inputfile)};


    for (auto& car : carDB["cars"]){
        meineFunktionen::print_car_json(car);
    }
}
