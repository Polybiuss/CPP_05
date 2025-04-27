#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include <fstream>

class AForm{
	private :
		const std::string _name;
		bool	_isSigned;
		const int _signGrade;
		const int _execGrade;
	
	public :
		AForm(void);
		AForm(std::string name, int signGrade, int execGrade);
		AForm(AForm const & fm);
		virtual ~AForm(void);
		std::string getName(void)const;
		bool getIsSigned(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;
		void	setIsSigned(bool);
		AForm& operator=(AForm const & fm);
		void	beSigned(Bureaucrat const & br);
		virtual void execute(Bureaucrat const & executor)const = 0;
		class GradeTooHighException : public std::exception{
			const char * what(void) const throw();
		};
		class GradeTooLowException : public std::exception{
			const char * what(void) const throw();
		};
		class NameEmptyException : public std::exception{
			const char * what(void) const throw();
		};
		class AlreadySignedException : public std::exception{
			const char * what(void) const throw();
		};
		class NotSignedException : public std::exception{
			const char * what(void) const throw();
		};
};

std::ostream & operator<<(std::ostream & o, AForm const & fm);

#endif