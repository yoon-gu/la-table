#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

int main()
{
	vector<double> v (3);
	for (unsigned i = 0; i < v.size (); ++ i)
	{
		v(i) = i;
	}
	std::cout << v << std::endl;
}