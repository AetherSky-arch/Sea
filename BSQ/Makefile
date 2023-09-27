NAME = BSQ

SRCS = parser.c \
utils.c \
utils2.c \
main.c \

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
PURPLE= \033[38;2;255;105;180m
RESET= \033[0m

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g3

OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS)
		${CC} $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "$(PURPLE)BSQ created!$(DEF_COLOR)"

all:	$(NAME)
		@echo "$(GREEN)BSQ compiled!$(DEF_COLOR)"

.c.o:
	${CC} ${CFLAGS} -I include -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

clean:
	@$(RM) ${OBJS}
	@echo "$(BLUE)BSQ object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)BSQ binary has been deleted$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for BSQ!$(DEF_COLOR)"
