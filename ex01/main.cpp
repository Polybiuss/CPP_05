#include "Form.hpp"

int main(void){
	Bureaucrat b1( 3, "bob" );
	Bureaucrat b2;
	Form f1("test", 3, 2);
	b1.signForm(f1);
	b2.signForm(f1);
	return (0);
}