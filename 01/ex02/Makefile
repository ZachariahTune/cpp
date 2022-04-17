NAME		=	main
SRCS		=	main.cpp

OBJS		=	$(SRCS:.cpp=.o)
CXX			=	c++ -std=c++98
CXXFLAGS	=	-Wall -Wextra -Werror
RM 			= 	rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -I ./ $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re