#include <iostream>
#include <vector>
#include <dirent.h>
#include <string.h>
#include <dlfcn.h>
#include "plugin.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "使い方: " << argv[0] << " <dirname:ディレクトリ名> <Left Operand:左項> <Right Operand:右項>" << std::endl;
        return 1;
    }

    // 引数から値を取得
    DIR *dir = opendir(argv[1]);
    double left_operand = std::stod(argv[2]);
    double right_operand = std::stod(argv[3]);

    std::vector<std::string> fileNames;

    struct dirent *file;
    while ((file = readdir(dir)) != nullptr)
    {
        if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0)
        {
            std::string fullPath = std::string(argv[1]) + "/" + file->d_name;
            fileNames.push_back(fullPath);
        }
    }

    for (auto fileName : fileNames)
    {
        void *handle = dlopen(fileName.c_str(), RTLD_LAZY);

        using CreateFunc = PluginInterface *(*)();
        CreateFunc create = reinterpret_cast<CreateFunc>(dlsym(handle, "new_instance"));
        PluginInterface *plugin = create();

        std::cout << plugin->getPluginName() << std::endl;
        std::cout << left_operand << plugin->getOperatorSymbol() << right_operand << "=" << plugin->exec(left_operand, right_operand) << std::endl;

        delete plugin;
        dlclose(handle);
    }

    return 0;
}