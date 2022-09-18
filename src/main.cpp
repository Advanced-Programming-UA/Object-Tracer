#include "exercises/demos.h"
#include "utils/TracerOutput.h"
#include <functional>
#include <iostream>
#include <map>

namespace {

using Function = std::function<int()>;

class FunctionRegister : public std::map<std::string, Function> {
public:
    ///
    bool is_valid(std::string const& fname) const { return find(fname) != end(); }

    ///
    void list(std::ostream& os) const {
        std::map<std::string, Function>::const_iterator itor;
        os << "The available exercises are:" << std::endl << std::endl;
        for (itor = begin(); itor != end(); itor++) {
            os << (*itor).first << std::endl;
        }
        os << std::endl;
    }
};
} // namespace

int main() {
    try {
        //----------------------------------------------------------------------
        // Setting up the register with available tests
        //----------------------------------------------------------------------
        FunctionRegister f_reg;
        f_reg["app_copy"] = app_copy;
        f_reg["app_essentialops"] = app_essentialops;
        f_reg["app_exception"] = app_exception;
        f_reg["app_fcalls"] = app_fcalls;
        f_reg["app_hierarchies"] = app_hierarchies;
        f_reg["app_poly1"] = app_poly1;
        f_reg["app_poly2"] = app_poly2;
        f_reg["app_example_exam_2021_1"] = app_example_exam_2021_1;
        f_reg["app_example_exam_2021_2"] = app_example_exam_2021_2;
        f_reg.list(std::cout);

        //----------------------------------------------------------------------
        // Set demo to execute
        //----------------------------------------------------------------------
        std::string choice;
        bool valid = false;
        std::ios_base::iostate old_state = std::cin.exceptions();
        std::cin.exceptions(std::ios_base::eofbit);
        while (!valid) {
            std::cout << "Select a demo by name: ";
            std::cin >> choice;
            if (f_reg.is_valid(choice)) {
                valid = true;
            } else {
                std::cout << "error on input: invalid demo name" << std::endl;
            }
        }
        std::cin.exceptions(old_state);

        //----------------------------------------------------------------------
        // Execute it.
        //----------------------------------------------------------------------
        if (!f_reg.is_valid(choice)) {
            throw std::runtime_error("error: unknown demo name cannot be executed");
        }

        f_reg[choice]();

        //----------------------------------------------------------------------
        // Log the output.
        //----------------------------------------------------------------------
        std::cout << std::endl << Utils::TracerOutput::getInstance() << std::endl;

        return (0);
    } catch (std::exception& e) {
        std::cerr << std::endl << "Caught std exception" << std::endl;
        std::cerr << e.what() << std::endl << "Exiting ..." << std::endl;
    } catch (...) {
        std::cerr << std::endl << "Caught unknown exception. Exiting ..." << std::endl;
    }

    return 0;
}
