NAME		=	myreplace
SRCS		=	main.cpp MyReplace.cpp
HEADS		=	MyReplace.hpp

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
				$(RM) *.replace

re:				fclean $(NAME)

.PHONY:			all clean fclean re