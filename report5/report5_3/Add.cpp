#include "plugin.hpp"

class Add : public PluginInterface
{
public:
    Add() {}
    ~Add() {}

    std::string getPluginName(void) override
    {
        return "Addition Plugin";
    }

    double exec(double a, double b) override
    {
        return a + b;
    }
};

#include <memory>
extern "C"
{
    PluginInterface *add_instance(void)
    {
        return new Add;
    }
}