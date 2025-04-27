#include "AForm.hpp"

AForm::AForm(void): _name("default_AForm"), _isSigned(false), _signGrade(150), _execGrade(150){
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade){
	if (name.empty())
		throw(NameEmptyException());
	if (signGrade > 150 || execGrade > 150)
		throw(GradeTooLowException());
	if (signGrade < 1 || execGrade < 1)
		throw(GradeTooHighException());
	std::cout << "Parameters AForm constructor called" << std::endl;
}

AForm::AForm(AForm const & fm): _name(fm._name), _isSigned(fm._isSigned), _signGrade(fm._signGrade), _execGrade(fm._execGrade){
	std::cout << "Copy AForm constructor called" << std::endl;
}

AForm::~AForm(void){
	std::cout << "Default AForm destructor called" << std::endl;
}

std::string AForm::getName(void) const {
	return _name;
}

bool AForm::getIsSigned(void) const {
	return _isSigned;
}

int AForm::getSignGrade(void) const {
	return _signGrade;
}

int AForm::getExecGrade(void) const {
	return _execGrade;
}

void	AForm::setIsSigned(bool bl){
	_isSigned = bl;
}

AForm& AForm::operator=(AForm const & fm){
	std::cout << "Default AForm destructor" << std::endl;
	this->_isSigned = fm._isSigned;
	return *this;
}

const char * AForm::GradeTooHighException::what(void) const throw(){
	return ("Grade too high");
}

const char * AForm::GradeTooLowException::what(void) const throw(){
	return ("Grade too low");
}

const char * AForm::NameEmptyException::what(void) const throw(){
	return ("Name can't be empty");
}

const char * AForm::AlreadySignedException::what(void) const throw(){
	return ("It's already SIGNED SCUMBAG!!");
}

const char * AForm::NotSignedException::what(void) const throw(){
	return("Form not signed!");
}

void	AForm::beSigned(Bureaucrat const & br){
	if (!_isSigned){
		if (br.getGrade() <= _signGrade)
			_isSigned = true;
		else
			throw(GradeTooLowException());
	}
	else
		throw(AlreadySignedException());
}

std::ostream & operator<<(std::ostream & o, AForm const & fm){
	o << "AForm " << fm.getName() << (fm.getIsSigned() ? ", who is signed" : ", who is not signed") << " whith " << fm.getSignGrade() << " grade to be signed and " << fm.getExecGrade() << " grade to be executed";
	return o;
}