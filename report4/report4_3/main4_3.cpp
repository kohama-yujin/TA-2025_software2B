#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <cstdlib> // キャスト

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "使い方: " << argv[0] << " <σ:標準偏差> <N:個数> <seed:乱数シード>" << std::endl;
        return 1;
    }

    // 引数から値を取得
    double sigma = std::atof(argv[1]);
    int N = std::atoi(argv[2]);
    std::uint32_t seed = (std::uint32_t)std::atoi(argv[3]);

    // メルセンヌ・ツイスタ乱数生成器
    std::mt19937 method(seed);

    // 正規分布オブジェクト
    std::normal_distribution<double> noise(0.0, sigma);

    std::vector<std::pair<double, double>> points;

    // 点の生成
    for (int alpha = 1; alpha <= N; alpha++)
    {
        double x = -10 + 20 * (alpha - 1) / (N - 1);
        double y = (3 * x + 4) / 2;

        // ノイズ付加
        double x_noisy = x + noise(method);
        double y_noisy = y + noise(method);

        points.emplace_back(x_noisy, y_noisy);
    }

    // 結果出力
    char filename[100];
    std::sprintf(filename, "data_N%d_sigma%.1f.dat", N, sigma);
    std::ofstream ofs(filename);
    for (auto [x, y] : points)
    {
        // std::cout << x << "," << y << std::endl;
        ofs << x << " " << y << std::endl;
    }

    return 0;
}