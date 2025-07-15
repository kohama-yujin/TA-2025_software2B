#include "plugin.hpp"

class Mul : public PluginInterface
{
public:
    Mul() {}
    ~Mul() {}

    std::string getPluginName(void) override
    {
        return "Multiplication Plugin";
    }

    std::string getOperatorSymbol(void) override
    {
        return "*";
    }

    double exec(double a, double b) override
    {
        return a * b;
    }
};

#include <memory>
extern "C"
{
    PluginInterface *new_instance(void)
    {
        return new Mul;
    }
}