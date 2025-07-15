#include <iostream>
#include <dlfcn.h>

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

    void *handle = dlopen("./libcalc.so", RTLD_LAZY);

    // C++スタイル
    auto add_func = reinterpret_cast<double (*)(double, double)>(dlsym(handle, "my_add"));
    double a = add_func(left_operand, right_operand);
    std::cout << a << std::endl;

    // Cスタイルキャスト
    double (*sub_func)(double, double) = (double (*)(double, double))dlsym(handle, "my_sub");
    double b = sub_func(left_operand, right_operand);
    std::cout << b << std::endl;

    dlclose(handle);

    return 0;
}