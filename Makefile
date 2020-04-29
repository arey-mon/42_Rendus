NAME = libftprintf.a

SRC =		ft_printf.c \
  			ft_printf_write.c \
			ft_printf_convert.c \
			ft_printf_convert2.c \
			ft_printf_checks.c \
			ft_printf_flags.c \
			ft_printf_flags_aff.c \
			ft_printf_neg.c \
			ft_printf_neg_prepare.c \
			ft_printf_p.c \
			ft_printf_strings.c
			

PATHSRCS = srcs

PATHTMP = tmp

HEADERS	= ./include

FLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix $(PATHSRCS)/,$(SRC))
OBJS = $(addprefix $(PATHTMP)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@(ar rc $(NAME) $(OBJS))
	@(ranlib $(NAME))

$(PATHTMP)/%.o: $(PATHSRCS)/%.c
	@(mkdir -p tmp)
	@(gcc $(FLAGS) -I $(HEADERS) -o $@ -c $<)

clean:
	${RM} ${OBJECTS} ${B_OBJECTS}

fclean:	clean
	${RM} ${NAME} ${B_OBJECTS}

re:	fclean all

.PHONY:	all clean fclean re
