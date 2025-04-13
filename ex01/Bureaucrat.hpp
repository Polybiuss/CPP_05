#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat{
	private :
		const std::string _name;
		int	_grade;
	
	public :
		Bureaucrat(int grade, std::string const name);
		~Bureaucrat(void);

		std::string const getName(void)const;
		int getGrade(void)const;
		std::string GradeTooHighException(void);
		std::string GradeTooLowException(void);
		std::string NameEmptyException(void);
		void	promote(void);
		void	demote(void);
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & br);

#endif