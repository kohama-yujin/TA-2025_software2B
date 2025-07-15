#include "plugin.hpp"

class Div : public PluginInterface
{
public:
    Div() {}
    ~Div() {}

    std::string getPluginName(void) override
    {
        return "Division Plugin";
    }

    std::string getOperatorSymbol(void) override
    {
        return "/";
    }

    double exec(double a, double b) override
    {
        return a / b;
    }
};

#include <memory>
extern "C"
{
    PluginInterface *new_instance(void)
    {
        return new Div;
    }
}