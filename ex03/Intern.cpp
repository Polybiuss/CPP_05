#include "Intern.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void){
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(Intern const & sg){
	(void)sg;
	std::cout << "Copy Intern constructor called" << std::endl;
}

Intern::~Intern(void){
	std::cout << "Default Intern desctructor called" << std::endl;
}

Intern& Intern::operator=(Intern const & sg){
	(void)sg;
	return *this;
}

AForm* Intern::makeForm(std::string form, std::string name){
	std::string arrform[] = {"ShruberryCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int j = 0;
	AForm *newForm;
	while (j < 3){
		if (form == arrform[j])
			break;
		++j;
	}
	switch (j)
	{
	case 0:
		newForm = new ShruberryCreationForm(name);
		break;

	case 1:
		newForm = new RobotomyRequestForm(name);
		break;
	
	case 2:
		newForm = new PresidentialPardonForm(name);
	default:
		newForm = NULL;
		break;
	}
	return newForm;
}