#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	public :
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(RobotomyRequestForm const & scf);
		~RobotomyRequestForm(void);

		RobotomyRequestForm& operator=(RobotomyRequestForm const & fm);
		void	execute(Bureaucrat const & executor)const;
};

# endif