NAME		=	easyfind
SRCS		=	main.cpp
HEADS		=	easyfind.hpp

# На Linux в версии С++98 не работают массивы std::ARRAY,
# Для подключения библиотеки <array> компилятор прямым текстом требует С++11 
# На MAC-ах такого нет - задание нужно сдавать на MAC-е
OBJS		=	$(SRCS:.cpp=.o)
CXX			=	c++ -std=c++98
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

re:				fclean $(NAME)

.PHONY:			all clean fclean re