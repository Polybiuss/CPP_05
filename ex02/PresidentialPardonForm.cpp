#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm::AForm("Shruberry", 25, 5){
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name): AForm::AForm(name, 25, 5){
	std::cout << "String PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & scf): AForm::AForm(scf){
	std::cout << "Copy PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void){
	std::cout << "Default PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & scf){
	this->setIsSigned(scf.getIsSigned());
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)const {
	if (!getIsSigned())
		throw(NotSignedException());
	else if (executor.getGrade() > getExecGrade())
		throw(GradeTooLowException());
	else{
		std::cout << executor << " has been pardoned by Zaphod Beeblerox" << std::endl;
	}
}