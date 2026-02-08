#include "base_shape.h"

std::map<std::string, Shape_Registry::Shape_creator>& Shape_Registry::get_registry() {
    static std::map<std::string, Shape_creator> journal;
    return journal;
}

void Shape_Registry::register_shape(std::string name, Shape_creator creator) {
    get_registry()[name] = creator;
}

std::unique_ptr<base_shape> Shape_Registry::create_shape(const std::string& name) {
    auto it = get_registry().find(name);
    if (it == get_registry().end()) return nullptr;
    return it->second();
}