#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"

class ShruberryCreationForm : public AForm{
	public :
		ShruberryCreationForm(void);
		ShruberryCreationForm(std::string name);
		ShruberryCreationForm(ShruberryCreationForm const & scf);
		~ShruberryCreationForm(void);

		ShruberryCreationForm& operator=(ShruberryCreationForm const & fm);
		void	execute(Bureaucrat const & executor)const;
};

# endif