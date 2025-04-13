#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade, std::string const name): _name(name){
	if (name.empty())
		throw(std::length_error(this->NameEmptyException()));
	if (grade > 150)
		throw(std::out_of_range(this->GradeTooHighException()));
	if (grade < 1)
		throw(std::out_of_range(this->NameEmptyException()));
	this->_grade = grade;
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void){
	std::cout << "Default Bureaucrat destructor called" << std::endl;
}

std::string const Bureaucrat::getName(void)const {
	return (this->_name);
}

int Bureaucrat::getGrade(void)const {
	return (this->_grade);
}

std::string Bureaucrat::GradeTooHighException(void){
	return ("Grade can't exceed 150");
}

std::string Bureaucrat::GradeTooLowException(void){
	return ("Grade can't be inferior to 1");
}

std::string Bureaucrat::NameEmptyException(void){
	return ("Name can't be empty");
}

void	Bureaucrat::promote(void){
	if (this->_grade - 1 < 1)
		throw(std::out_of_range(this->GradeTooLowException()));
	--this->_grade; 
}

void	Bureaucrat::demote(void){
	if (this->_grade + 1 > 150)
		throw(std::out_of_range(this->GradeTooHighException()));
	++this->_grade;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & br){
	o << br.getName() << ", bureaucrat grade " << br.getGrade() << ".";
	return o;
}