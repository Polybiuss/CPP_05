#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	public :
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(PresidentialPardonForm const & scf);
		~PresidentialPardonForm(void);

		PresidentialPardonForm& operator=(PresidentialPardonForm const & fm);
		void	execute(Bureaucrat const & executor)const;
};

# endif