#include <iostream>
#include <memory>
#include <dlfcn.h>
#include "plugin.hpp"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "使い方: " << argv[0] << " <Left Operand:左項> <Right Operand:右項>" << std::endl;
        return 1;
    }

    // 引数から値を取得
    double left_operand = std::stod(argv[1]);
    double right_operand = std::stod(argv[2]);

    void *handle = dlopen("./libAdd.so", RTLD_LAZY);

    using CreateFunc = PluginInterface *(*)();
    CreateFunc create = reinterpret_cast<CreateFunc>(dlsym(handle, "add_instance"));
    PluginInterface *instance = create();

    std::cout << instance->getPluginName() << std::endl;
    std::cout << instance->exec(left_operand, right_operand) << std::endl;

    dlclose(handle);

    return 0;
}