#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Form;

class Bureaucrat{
	private :
		const std::string _name;
		int	_grade;
	
	public :
		Bureaucrat(void);
		Bureaucrat(int grade, std::string const name);
		Bureaucrat(Bureaucrat const & br);
		~Bureaucrat(void);

		Bureaucrat& operator=(Bureaucrat const & br);
		std::string const getName(void)const;
		int getGrade(void)const;
		void	promote(void);
		void	demote(void);
		void	signForm(Form & fm);
		class GradeTooHighException : public std::exception{
			public : 
				const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception{
			public :
				const char * what() const throw();
		};
		class NameEmptyException : public std::exception{
			public :
				const char * what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & br);

#endif