#include <iostream>
#include <boost/numeric/ublas/symmetric.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace ublas = boost::numeric::ublas;

ublas::matrix<double> get_A(int N, double a0 = 1, double a1 = 1)
{
	ublas::identity_matrix<double> I(N, N);
	ublas::matrix<double> m1 = 2.0 * I;
	m1(0, 0) = a0;
	m1(N-1, N-1) = a1;

	ublas::symmetric_matrix<double, ublas::lower> m2(N, N);
	for (unsigned i = 0; i < m2.size1(); ++ i)
		for (unsigned j = 0; j <= i; ++ j)
			m2(i, j) = (j == i-1)? -1:0;
	return m1 + m2;
}

ublas::matrix<double> get_K(int N)
{
	ublas::identity_matrix<double> I(N, N);
	ublas::matrix<double> m1 = 2.0 * I;

	ublas::symmetric_matrix<double, ublas::lower> m2(N, N);
	for (unsigned i = 0; i < m2.size1(); ++ i)
		for (unsigned j = 0; j <= i; ++ j)
			m2(i, j) = (j == i-1)? -1:0;
	return m1 + m2;
}

int main()
{
	int N = 4;
	double h = 1.0 / (N - 1);
	ublas::matrix<double> K = get_K(N);
	std::cout << K << std::endl;

	ublas::matrix<double> A = get_A(N);
	std::cout << A << std::endl;

	ublas::matrix<double> A1 = get_A(N, 2, 1);
	std::cout << A1 << std::endl;

	ublas::matrix<double> A2 = get_A(N, 1, 2);
	std::cout << A2 << std::endl;

	return 0;
}