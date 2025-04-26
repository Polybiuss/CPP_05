#include "Bureaucrat.hpp"

int main(void){
	try{
		Bureaucrat bob(150, "");
		std::cout << bob << std::endl;
		bob.demote();
		std::cout << bob << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException & e){
		std::cout << "Err Bureaucrat class high grade : " << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException & e){
		std::cout << "Err Bureaucrat class low grade : " << e.what() << std::endl;
	}
	catch(Bureaucrat::NameEmptyException & e){
		std::cout << "Err Bureaucrat name : " << e.what() << std::endl;
	}
	catch(std::exception & e){
		std::cout << "Err exception class : " << e.what() << std::endl;
	}
	return (0);
}