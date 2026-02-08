#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <cmath>
#include <vector>
#include <functional>

#include "base_shape.h"


using namespace std;

int main(int argc, char* argv[]) {
    // 2. Validate CLI Arguments (Expect: ./program <name> <side1> <side2>...)
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <shape_name> <side1> [side2...]" << endl;
        return 1;
    }

    string shape_name = argv[1];
    auto shape = Shape_Registry::create_shape(shape_name);

    if (!shape) {
        cout << "Error: Unknown shape '" << shape_name << "'" << endl;
        return 1;
    }


    for (int i = 2; i < argc; ++i) {
        shape->sides.push_back(stof(argv[i]));
    }

    shape->area_calc();
    shape->perimeter_calc();
    shape->describe();

    return 0;
}