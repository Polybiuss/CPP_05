#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Default"), _grade(150){
	std::cout << "Default Bureaucrat constructor" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & br): _name(br._name), _grade(br._grade){
	std::cout << "Copy Bureaucrat constructor" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, std::string const name): _name(name){
	if (name.empty())
		throw(NameEmptyException());
	if (grade > 150)
		throw(GradeTooHighException());
	if (grade < 1)
		throw(GradeTooLowException());
	this->_grade = grade;
	std::cout << "Parameter Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void){
	std::cout << "Default Bureaucrat destructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & br){
	this->_grade = br._grade;
	return *this;
}

std::string const Bureaucrat::getName(void)const {
	return (this->_name);
}

int Bureaucrat::getGrade(void)const {
	return (this->_grade);
}

const char * Bureaucrat::GradeTooHighException::what(void)const throw() {
	return ("Grade can't be inferior to 1");
}

const char * Bureaucrat::GradeTooLowException::what(void)const throw() {
	return ("Grade can't exceed 150");
}

const char * Bureaucrat::NameEmptyException::what(void)const throw() {
	return ("Name can't be empty");
}

void	Bureaucrat::promote(void){
	if (this->_grade - 1 < 1)
		throw(GradeTooLowException());
	--this->_grade; 
}

void	Bureaucrat::demote(void){
	if (this->_grade + 1 > 150)
		throw(GradeTooHighException());
	++this->_grade;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & br){
	o << br.getName() << ", bureaucrat grade " << br.getGrade() << ".";
	return o;
}