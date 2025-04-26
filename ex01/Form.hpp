#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form{
	private :
		const std::string _name;
		bool	_isSigned;
		const int _signGrade;
		const int _execGrade;
	
	public :
		Form(void);
		Form(std::string name, int signGrade, int execGrade);
		Form(Form const & fm);
		~Form(void);
		std::string getName(void)const;
		bool getIsSigned(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;
		Form& operator=(Form const & fm);
		void	beSigned(Bureaucrat const & br);
		class GradeTooHighException : public std::exception{
			const char * what(void) const throw();
		};
		class GradeTooLowException : public std::exception{
			const char * what(void) const throw();
		};
		class NameEmptyException : public std::exception{
			const char * what(void) const throw();
		};
		class AlreadySingedException : public std::exception{
			const char * what(void) const throw();
		};
};

std::ostream & operator<<(std::ostream & o, Form const & fm);

#endif