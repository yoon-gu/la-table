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

	// scalar * Matrix
	matrix<double> mm (3, 3);
	for (unsigned i = 0; i < mm.size1 (); ++ i)
		for (unsigned j = 0; j < mm.size2 (); ++ j)
			mm (i, j) = 3 * i + j;

	std::cout << "2 * matrix \t" << 2.0 * mm << std::endl;
	std::cout << "matrix * 2 \t" << mm * 2.0 << std::endl;

	// Matrix * Vector
	matrix<double> m_ (3, 3);
	vector<double> v (3);
	for (unsigned i = 0; i < std::min (m_.size1 (), v.size ()); ++ i) {
		for (unsigned j = 0; j < m_.size2 (); ++ j)
			m_ (i, j) = 3 * i + j;
		v (i) = i;
	}

	std::cout << "matrix * vector (A * b) \t" << prod (m_, v) << std::endl;
	std::cout << "vector * matrix (A' * b)\t" << prod (v, m_) << std::endl;   

	// Matrix * Matrix
	matrix<double> m11 (3, 3), m22 (3, 3);
	for (unsigned i = 0; i < std::min (m11.size1 (), m22.size1 ()); ++ i)
		for (unsigned j = 0; j < std::min (m11.size2 (), m22.size2 ()); ++ j)
			m11 (i, j) = m22 (i, j) = 3 * i + j;

	std::cout << "matrix * matrix (A * B) \t" << prod (m11, m22) << std::endl;
	return 0;
}