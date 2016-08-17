#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

int main()
{
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

    return 0;
}