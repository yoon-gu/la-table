#include <iostream>
#include <boost/numeric/ublas/symmetric.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

matrix<double> K_matrix(int N)
{
	identity_matrix<double> I(N, N);
	matrix<double> m1 = 2.0 * I;

	symmetric_matrix<double, lower> m2(N, N);
	for (unsigned i = 0; i < m2.size1(); ++ i)
		for (unsigned j = 0; j <= i; ++ j)
			m2(i, j) = (j == i-1)? -1:0;
	return m1 + m2;
}

int main()
{
	int N = 5;
	double h = 1.0 / (N - 1);
	matrix<double> K = K_matrix(N);
	std::cout << K << std::endl;

	return 0;
}