#ifndef BASE_SHAPE_H
#define BASE_SHAPE_H

#include <vector>
#include <string>
#include <memory>
#include <map>
#include <functional>

class base_shape {
public:
    std::vector<float> sides;
    float perimeter = 0;
    float area = 0;

    virtual ~base_shape() {}
    virtual void perimeter_calc() = 0;
    virtual void area_calc() = 0;
    virtual void describe() = 0;
};

class Shape_Registry {
public:
    using Shape_creator = std::function<std::unique_ptr<base_shape>()>;
    static std::unique_ptr<base_shape> create_shape(const std::string& name);
    static void register_shape(std::string name, Shape_creator creator);
private:

    static std::map<std::string, Shape_creator>& get_registry();
};

#endif