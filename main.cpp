#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

int main()
{
	std::cout << "\nVector" << std::endl;
	// basic Vector Usage
	vector<double> v(3);
	for (unsigned i = 0; i < v.size(); ++ i)
	{
		v(i) = i;
	}
	std::cout << "vector \t\t" << v << std::endl;

	// unit_vector
	for (int i = 0; i < 3; ++ i) 
	{
		unit_vector<double> v_unit(3, i);
		std::cout << "unit_vector \t" << v_unit << std::endl;
	}

	// zero_vector
	zero_vector<double> v_zero(3);
	std::cout << "zero_vector \t" << v_zero << std::endl;

	// scalr_vector
	scalar_vector<double> v_scalar(3,100);
	std::cout << "scalar_vector \t" << v_scalar << std::endl;

	std::cout << "\nMatrix" << std::endl;
	// basic matrix
	matrix<double> m(3, 3);
	for (unsigned i = 0; i < m.size1 (); ++ i)
	{
		for (unsigned j = 0; j < m.size2 (); ++ j)
		{
			m (i, j) = 3 * i + j;
		}
	}
	std::cout << "matrix \t\t" << m << std::endl;

	// identity matrix
	identity_matrix<double> m_identity(3);
    std::cout << "eye matrix\t" << m_identity << std::endl;

    // zero matrix
    zero_matrix<double> m_zero(3, 3);
    std::cout << "zero matrix\t" << m_zero << std::endl;

    // scalar matrix
    scalar_matrix<double> m_scalar(3, 3, 100);
    std::cout << "scalar matrix\t" << m_scalar << std::endl;
	return 0;
}