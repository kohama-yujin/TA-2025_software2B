#include <iostream>
#include <vector>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "使い方: " << argv[0] << " <dirname:ディレクトリ名>" << std::endl;
        return 1;
    }

    // 引数から値を取得
    DIR *dir = opendir(argv[1]);

    std::vector<std::string> fileNames;

    struct dirent *file;
    while ((file = readdir(dir)) != nullptr)
    {
        if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0)
        {
            fileNames.push_back(file->d_name);
        }
    }

    for (auto fileName : fileNames)
    {
        std::cout << fileName << std::endl;
    }

    return 0;
}