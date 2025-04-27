#include "Bureaucrat.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){
	AForm *scf = new PresidentialPardonForm("test");
	Bureaucrat bob(1, "bob");

	bob.signForm(*scf);
	bob.executeForm(*scf);
	delete scf;
	return (0);
}