#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void): AForm::AForm("Shruberry", 72, 45){
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name): AForm::AForm(name, 72, 45){
	std::cout << "String RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & scf): AForm::AForm(scf){
	std::cout << "Copy RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void){
	std::cout << "Default RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & scf){
	this->setIsSigned(scf.getIsSigned());
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)const {
	if (!getIsSigned())
		throw(NotSignedException());
	else if (executor.getGrade() > getExecGrade())
		throw(GradeTooLowException());
	else{
		std::srand(std::time(0));
		int nb = std::rand() % 100 + 1;
		std::cout << "beep boo beboeboeboobzzzzrrrr" << std::endl;
		if (nb % 2)
			std::cout << "task executed succesfully" << std::endl;
		else
			std::cout << "task failed succesfully" << std::endl; 
	}
}