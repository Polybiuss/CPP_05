#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern{
	public:
		Intern(void);
		Intern(Intern const & sg);
		~Intern(void);

		Intern& operator=(Intern const & sg);

		AForm* makeForm(std::string form, std::string name);
};

#endif