#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void add_shape_to_file(string filename, string name, string area_formula, string perim_formula) {
    ofstream outFile(filename, ios::app); // Open in append mode

    if (!outFile) {
        cerr << "Error: Could not open " << filename << endl;
        return;
    }

    
    outFile << "\n" <<" // AUTO-GENERATED SHAPE: " << name << "\n\n";
    outFile << "class " << name << " : public base_shape {\n";
    outFile << "public:\n";
    outFile << "    void describe() override {\n";
    outFile << "        area_calc();\n";
    outFile << "        perimeter_calc();\n";
    outFile << "        std::cout << \"Shape: " << name << " | Area: \" << area << \" | Perimeter: \" << perimeter << std::endl;\n";
    outFile << "    }\n\n";
    outFile << "private:\n";
    outFile << "    void area_calc() override {\n";
    outFile << "        this->area = " << area_formula << ";\n";
    outFile << "    }\n";
    outFile << "    void perimeter_calc() override {\n";
    outFile << "        this->perimeter = " << perim_formula << ";\n";
    outFile << "    }\n";
    outFile << "};\n\n";
    
    // The magic registration block
    outFile << "static bool " << name << "_registered = []() {\n";
    outFile << "    Shape_Registry::register_shape(\"" << name << "\", []() { return std::make_unique<" << name << ">(); });\n";
    outFile << "    return true;\n";
    outFile << "}();\n";

    outFile.close();
    cout << "Successfully added " << name << " to " << filename << endl;
}

int main() {
    string name, area, perim;

    cout << "--- Shape Knowledge Base Updater ---\n";
    cout << "Enter shape name (lowercase): ";
    cin >> name;
    cin.ignore(); // clear buffer

    cout << "Enter C++ area formula (e.g., sides[0] * sides[1]): ";
    getline(cin, area);

    cout << "Enter C++ perimeter formula (e.g., 2 * (sides[0] + sides[1])): ";
    getline(cin, perim);

    add_shape_to_file("objects.cpp", name, area, perim);

    cout << "\nNext Step: Recompile the project to add the new shape!\n";
    return 0;
}