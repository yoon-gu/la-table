// #include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/symmetric.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

int main()
{
	int N = 5;
	double h = 1.0 / (N - 1);
	identity_matrix<double> I(N, N);
	matrix<double> m1 = 2 * I;
	
	symmetric_matrix<double, lower> m2(N, N);
	for (unsigned i = 1; i < m2.size1(); ++ i)
	{
		for (unsigned j = 0; j <= i; ++ j)
		{
			if (j == i-1)
			{
				m2(i, i-1) = -1;
			}
			else
			{
				m2(i, j) = 0;
			}
		}
	}
			
	std::cout << m1 + m2 << std::endl;
	
	return 0;
}