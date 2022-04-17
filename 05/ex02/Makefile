NAME		=	form
SRCS		=	main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
HEADS		=	Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

# На Linux в версии С++98 не работает открытие файлов,
# компилятор ругается, что при открытии файла его имя должно передаваться строкой стандарта С++11
# На MAC-ах такого нет - задание нужно сдавать на MAC-е
OBJS		=	$(SRCS:.cpp=.o)
CXX			=	c++ -std=c++11
CXXFLAGS	=	-Wall -Wextra -Werror
RM 			= 	rm -f

all:			$(NAME)

%.o:%.cpp $(HEADS)
				$(CXX) $(CXXFLAGS) -I ./ -o $@ -c $<

$(NAME):		$(OBJS) $(HEADS)
				$(CXX) $(CXXFLAGS) -I ./ $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)
				$(RM) *_shrubbery

re:				fclean $(NAME)

.PHONY:			all clean fclean re