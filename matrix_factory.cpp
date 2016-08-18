#include <iostream>
#include <boost/numeric/ublas/symmetric.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace ublas = boost::numeric::ublas;

ublas::matrix<double> get_K(int N, double a0 = 2, double a1 = 2)
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

int main()
{
	int N = 3;
	double h = 1.0 / (N - 1);
	ublas::matrix<double> K = get_K(N);
	std::cout << K << std::endl;

	ublas::matrix<double> A = get_K(N, 1, 1);
	std::cout << A << std::endl;

	ublas::matrix<double> A1 = get_K(N, 2, 1);
	std::cout << A1 << std::endl;

	ublas::matrix<double> A2 = get_K(N, 1, 2);
	std::cout << A2 << std::endl;

	ublas::matrix<double> Kinv(N, N);
	Kinv.assign(ublas::identity_matrix<double> (K.size1()));
	ublas::permutation_matrix<size_t> pm(K.size1());
	ublas::lu_factorize(K, pm);
	ublas::lu_substitute(K, pm, Kinv);

	std::cout << Kinv << std::endl;
	return 0;
}