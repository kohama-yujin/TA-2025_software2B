#include <iostream>
#include <Eigen/Dense>

int main(int argc, char *argv[])
{
    // ベクトル
    Eigen::VectorXd a = Eigen::VectorXd::Zero(3);
    Eigen::VectorXd b = Eigen::VectorXd::Zero(3);
    a << 1, 2, 3;
    b = Eigen::VectorXd::Ones(3);

    std::cout << "a+b" << std::endl;
    std::cout << a + b << std::endl;

    std::cout << "ab^T" << std::endl;
    std::cout << a * b.transpose() << std::endl;

    std::cout << "a^Tb" << std::endl;
    std::cout << a.transpose() * b << std::endl;

    // 行列
    Eigen::MatrixXd A = Eigen::MatrixXd::Zero(3, 3);
    Eigen::MatrixXd B = Eigen::MatrixXd::Zero(3, 3);
    A.col(0) = a;
    a << 4, 5, 6;
    A.col(1) = a;
    a << 7, 8, 9;
    A.col(2) = a;
    B = Eigen::MatrixXd::Identity(3, 3);

    std::cout << "A" << std::endl;
    std::cout << A << std::endl;
    std::cout << "B" << std::endl;
    std::cout << B << std::endl;

    std::cout << "Ab" << std::endl;
    std::cout << A * b << std::endl;

    std::cout << "AB" << std::endl;
    std::cout << A * B << std::endl;
}