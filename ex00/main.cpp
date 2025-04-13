#include "Bureaucrat.hpp"

int main(void){
	try{
		Bureaucrat bob(150, "bob");
		std::cout << bob << std::endl;
		bob.demote();
		std::cout << bob << std::endl;
	}
	catch(std::length_error & e)
	{
		std::cout << "Length error : " << e.what() << std::endl;
	}
	catch(std::out_of_range & e)
	{
		std::cout << "Out of range error : " << e.what() << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << "Exception error : " << e.what() << std::endl;
	}
	return (0);
}