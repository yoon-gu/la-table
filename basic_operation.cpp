#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

int main()
{
    // op(Matrix)
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

    // Matrix +/- Matrix
    matrix<double> m1 (3, 3), m2 (3, 3);
    for (unsigned i = 0; i < std::min (m1.size1 (), m2.size1 ()); ++ i)
        for (unsigned j = 0; j < std::min (m1.size2 (), m2.size2 ()); ++ j)
            m1 (i, j) = m2 (i, j) = 3 * i + j;

    std::cout << "add \t" << m1 + m2 << std::endl;
    std::cout << "subt \t" << m1 - m2 << std::endl;
	return 0;
}