#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

int main()
{
	matrix<std::complex<double> > m (3, 3);
    for (unsigned i = 0; i < m.size1 (); ++ i)
        for (unsigned j = 0; j < m.size2 (); ++ j)
            m (i, j) = std::complex<double> (3 * i + j, 3 * i + j);

    std::cout << "minus \t" << - m << std::endl;
    std::cout << "conj \t" << conj (m) << std::endl;
    std::cout << "real \t" << real (m) << std::endl;
    std::cout << "imag \t" << imag (m) << std::endl;
    std::cout << "trans \t" << trans (m) << std::endl;
    std::cout << "herm \t" << herm (m) << std::endl;

	return 0;
}