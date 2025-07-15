#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>
#include <string>
#include <sstream>

int main(int argc, char *argv[])
{
    std::ifstream infile("../report4_3/data_N100_sigma2.0.dat");
    if (!infile)
    {
        std::cerr << "ファイルが開けませんでした。" << std::endl;
        return 1;
    }

    // .datのデータ取得用
    std::vector<Eigen::Vector3d> points;
    std::string line;
    double x, y;
    // .datからデータベクトルvectorに変換
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        if (iss >> x >> y)
        {
            points.emplace_back(Eigen::Vector3d(x, y, 1.0));
        }
    }

    // 行列
    Eigen::Matrix3d M = Eigen::Matrix3d::Zero();
    for (auto x_alpha : points)
    {
        M += x_alpha * x_alpha.transpose();
    }

    // 固有値分解
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigensolver(M);
    // 固有値（小さい順にソート）
    Eigen::Vector3d evals = eigensolver.eigenvalues();
    // 固有ベクトル（小さい順にソート）
    Eigen::Matrix3d evecs = eigensolver.eigenvectors();
    // 最小固有値の固有ベクトル
    Eigen::Vector3d mu = evecs.col(0);

    std::cout << "μ=\n"
              << mu << std::endl;
    std::cout << "a=" << mu(0) / -mu(1) << std::endl;
    std::cout << "b=" << mu(2) / -mu(1) << std::endl;

    return 0;
}