#include <iostream>
#include <random>
#include <vector>
#include <numeric> // 合計（accumulate）
#include <cstdlib> // キャスト

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        std::cerr << "使い方: " << argv[0] << " <μ:平均> <σ:標準偏差> <N:個数> <seed:乱数シード>" << std::endl;
        return 1;
    }

    // 引数から値を取得
    double mu = std::atof(argv[1]);
    double sigma = std::atof(argv[2]);
    int N = std::atoi(argv[3]);
    std::uint32_t seed = (std::uint32_t)std::atoi(argv[4]);

    // メルセンヌ・ツイスタ乱数生成器
    std::mt19937 method(seed);

    // 正規分布オブジェクト
    std::normal_distribution<double> dist(mu, sigma);

    std::vector<double> data;

    // 乱数生成
    for (int i = 0; i < N; ++i)
    {
        data.push_back(dist(method));
    }

    // 標本平均の計算
    double ave = std::accumulate(data.begin(), data.end(), 0.0) / N;

    // 標本分散の計算
    double variance = 0.0;
    for (double elem : data)
    {
        variance += (elem - ave) * (elem - ave);
    }
    variance /= (N - 1); // 不偏分散

    // 結果出力
    std::cout << "標本平均: " << ave << std::endl;
    std::cout << "標本分散: " << variance << std::endl;

    return 0;
}