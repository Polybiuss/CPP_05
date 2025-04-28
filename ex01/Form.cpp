#include "Form.hpp"

Form::Form(void): _name("default_form"), _isSigned(false), _signGrade(150), _execGrade(150){
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade){
	if (name.empty())
		throw(NameEmptyException());
	if (signGrade > 150 || execGrade > 150)
		throw(GradeTooHighException());
	if (signGrade < 1 || execGrade < 1)
		throw(GradeTooLowException());
	std::cout << "Parameters Form constructor called" << std::endl;
}

Form::Form(Form const & fm): _name(fm._name), _isSigned(fm._isSigned), _signGrade(fm._signGrade), _execGrade(fm._execGrade){
	std::cout << "Copy Form constructor called" << std::endl;
}

Form::~Form(void){
	std::cout << "Default Form destructor called" << std::endl;
}

std::string Form::getName(void) const {
	return _name;
}

bool Form::getIsSigned(void) const {
	return _isSigned;
}

int Form::getSignGrade(void) const {
	return _signGrade;
}

int Form::getExecGrade(void) const {
	return _execGrade;
}

Form& Form::operator=(Form const & fm){
	std::cout << "Default Form destructor" << std::endl;
	this->_isSigned = fm._isSigned;
	return *this;
}

const char * Form::GradeTooHighException::what(void) const throw(){
	return ("Grade can't too high");
}

const char * Form::GradeTooLowException::what(void) const throw(){
	return ("Grade too low");
}

const char * Form::NameEmptyException::what(void) const throw(){
	return ("Name can't be empty");
}

const char * Form::AlreadySingedException::what(void) const throw(){
	return ("It's already SIGNED SCUMBAG!!");
}

void	Form::beSigned(Bureaucrat const & br){
	if (!_isSigned){
		if (br.getGrade() <= _signGrade)
			_isSigned = true;
		else
			throw(GradeTooLowException());
	}
	else
		throw(AlreadySingedException());
}

std::ostream & operator<<(std::ostream & o, Form const & fm){
	o << "Form " << fm.getName() << (fm.getIsSigned() ? ", who is signed" : ", who is not signed") << " whith " << fm.getSignGrade() << " grade to be signed and " << fm.getExecGrade() << " grade to be executed.";
	return o;
}