#include "ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm(void): AForm::AForm("Shruberry", 145, 137){
	std::cout << "Default ShruberryCreationForm constructor called" << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(std::string name): AForm::AForm(name, 145, 137){
	std::cout << "String ShruberryCreationForm constructor called" << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(ShruberryCreationForm const & scf): AForm::AForm(scf){
	std::cout << "Copy ShruberryCreationForm constructor called" << std::endl;
}

ShruberryCreationForm::~ShruberryCreationForm(void){
	std::cout << "Default ShruberryCreationForm destructor called" << std::endl;
}

ShruberryCreationForm& ShruberryCreationForm::operator=(ShruberryCreationForm const & scf){
	this->setIsSigned(scf.getIsSigned());
	return *this;
}

void ShruberryCreationForm::execute(Bureaucrat const & executor)const {
	if (!getIsSigned())
		throw(NotSignedException());
	else if (executor.getGrade() > getExecGrade())
		throw(GradeTooLowException());
	else{
		std::string file(getName() + "_shruberry");
		std::ofstream fb(file.c_str());
		if (fb.is_open()){
			fb <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			std::endl;
			fb.close();
		}
		else
			throw (std::ios_base::failure("Error : can't open file " + file));
	}
}