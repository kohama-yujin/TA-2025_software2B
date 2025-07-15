#include "plugin.hpp"

class Sub : public PluginInterface
{
public:
    Sub() {}
    ~Sub() {}

    std::string getPluginName(void) override
    {
        return "Subtraction Plugin";
    }

    std::string getOperatorSymbol(void) override
    {
        return "-";
    }

    double exec(double a, double b) override
    {
        return a - b;
    }
};

#include <memory>
extern "C"
{
    PluginInterface *new_instance(void)
    {
        return new Sub;
    }
}