NAME = libasm.a

ASM = nasm
AFLAGS = -felf64

SRC =	ft_strlen.s \
	ft_strcpy.s \
	#ft_strcmp.s \
	#ft_strdup.s \
	#ft_read.s \
	#ft_write.s \

OBJ = $(SRC:.s=.o)
OBJDIR = objs/

%.o: %.s
	$(ASM) $(AFLAGS) $< -o $@

OPTION = -I .

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	mkdir -p $(OBJDIR)
	ar rcs $(NAME) $(OBJ)
	mv *.o $(OBJDIR)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
