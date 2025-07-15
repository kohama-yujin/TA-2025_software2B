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
    std::vector<Eigen::Vector3d> points; // 最小2乗法用
    std::vector<double> x_vals, y_vals;  // 正規方程式用
    std::string line;
    double x, y;

    // .datからデータベクトルvectorに変換
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        if (iss >> x >> y)
        {
            // 最小2乗法用のベクトル
            points.emplace_back(Eigen::Vector3d(x, y, 1.0));
            // 正規方程式用のx, y値
            x_vals.push_back(x);
            y_vals.push_back(y);
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
    // 最小固有値の値
    std::cout << "μ=\n"
              << mu << std::endl;
    std::cout << "a=" << mu(0) / -mu(1) << std::endl;
    std::cout << "b=" << mu(2) / -mu(1) << std::endl;

    // 正規方程式
    int N = x_vals.size();
    double Sx = 0, Sy = 0, Sxx = 0, Sxy = 0;
    for (int i = 0; i < N; ++i)
    {
        Sx += x_vals[i];
        Sy += y_vals[i];
        Sxx += x_vals[i] * x_vals[i];
        Sxy += x_vals[i] * y_vals[i];
    }

    // 正規方程式の行列とベクトル
    Eigen::Matrix2d A;
    A << Sxx, Sx,
        Sx, N;
    Eigen::Vector2d B;
    B << Sxy,
        Sy;
    // 正規方程式の解
    Eigen::Vector2d result = A.colPivHouseholderQr().solve(B);
    double a = result(0);
    double b = result(1);
    // 正規方程式の値
    std::cout << "最小二乗法による直線当てはめ:" << std::endl;
    std::cout << "y = " << a << "x + " << b << std::endl;

    return 0;
}