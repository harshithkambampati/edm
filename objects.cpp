#include "base_shape.h"
#include <iostream>
#include <cmath>
#ifndef PI
#define PI 3.14159265358979323846
#endif
class triangle : public base_shape {
public:
    void perimeter_calc() override {
        perimeter = 0;
        for(float s : sides) perimeter += s;
    }

    void area_calc() override {
        if (sides.size() < 3) return;
        // Heron's Formula
        float s = (sides[0] + sides[1] + sides[2]) / 2;
        area = sqrt(s * (s - sides[0]) * (s - sides[1]) * (s - sides[2]));
    }

    void describe() override {
        area_calc();
        perimeter_calc();
        std::cout << "Shape: Triangle | Area: " << area << " | Perimeter: " << perimeter << std::endl;
    }
};


static bool triangle_registered = []() {
    Shape_Registry::register_shape("triangle", []() { 
        return std::make_unique<triangle>(); 
    });
    return true;
}();
 // AUTO-GENERATED SHAPE: circle

class circle : public base_shape {
public:
    void describe() override {
        area_calc();
        perimeter_calc();
        std::cout << "Shape: circle | Area: " << area << " | Perimeter: " << perimeter << std::endl;
    }

private:
    void area_calc() override {
        this->area = PI*sides[0]*sides[0];
    }
    void perimeter_calc() override {
        this->perimeter = 2*PI*sides[0];
    }
};

static bool circle_registered = []() {
    Shape_Registry::register_shape("circle", []() { return std::make_unique<circle>(); });
    return true;
}();

 // AUTO-GENERATED SHAPE: square
// ==========================================
class square : public base_shape {
public:
    void describe() override {
        area_calc();
        perimeter_calc();
        std::cout << "Shape: square | Area: " << area << " | Perimeter: " << perimeter << std::endl;
    }

private:
    void area_calc() override {
        this->area = sides[0]*sides[0];
    }
    void perimeter_calc() override {
        this->perimeter = 4*sides[0];
    }
};

static bool square_registered = []() {
    Shape_Registry::register_shape("square", []() { return std::make_unique<square>(); });
    return true;
}();

 // AUTO-GENERATED SHAPE: rect
// ==========================================
class rect : public base_shape {
public:
    void describe() override {
        area_calc();
        perimeter_calc();
        std::cout << "Shape: rect | Area: " << area << " | Perimeter: " << perimeter << std::endl;
    }

private:
    void area_calc() override {
        this->area = sides[0]*sides[1];
    }
    void perimeter_calc() override {
        this->perimeter = 2*(sides[0]+sides[1]);
    }
};

static bool rect_registered = []() {
    Shape_Registry::register_shape("rect", []() { return std::make_unique<rect>(); });
    return true;
}();
