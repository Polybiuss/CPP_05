#include "Bureaucrat.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void){
	Intern bob;
	Bureaucrat rene(1, "rene");
	AForm *newform = bob.makeForm("ShruberryCreationForm", "test");
	if (!newform)
		std::cout << "this form is empty" << std::endl;
	else{
		std::cout << "this form is created" << std::endl;
		rene.signForm(*newform);
		rene.executeForm(*newform);
		delete newform;
	}
	return (0);
}