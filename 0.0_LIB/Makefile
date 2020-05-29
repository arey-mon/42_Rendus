# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apreymon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 19:09:32 by apreymon          #+#    #+#              #
#    Updated: 2019/11/20 19:09:43 by apreymon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= libft.a

SRCS				= ${SRCS_DIR}/ft_atoi.c \
					  ${SRCS_DIR}/ft_bzero.c \
					  ${SRCS_DIR}/ft_calloc.c \
					  ${SRCS_DIR}/ft_isalnum.c \
					  ${SRCS_DIR}/ft_isalpha.c \
					  ${SRCS_DIR}/ft_isascii.c \
					  ${SRCS_DIR}/ft_isdigit.c \
					  ${SRCS_DIR}/ft_isprint.c \
					  ${SRCS_DIR}/ft_itoa.c \
					  ${SRCS_DIR}/ft_memccpy.c \
					  ${SRCS_DIR}/ft_memchr.c \
					  ${SRCS_DIR}/ft_memcmp.c \
					  ${SRCS_DIR}/ft_memcpy.c \
					  ${SRCS_DIR}/ft_memmove.c \
					  ${SRCS_DIR}/ft_memset.c \
					  ${SRCS_DIR}/ft_putchar_fd.c \
					  ${SRCS_DIR}/ft_putendl_fd.c \
					  ${SRCS_DIR}/ft_putnbr_fd.c \
					  ${SRCS_DIR}/ft_putstr_fd.c \
					  ${SRCS_DIR}/ft_split.c \
					  ${SRCS_DIR}/ft_strchr.c \
					  ${SRCS_DIR}/ft_strdup.c \
					  ${SRCS_DIR}/ft_strjoin.c \
					  ${SRCS_DIR}/ft_strlcpy.c \
					  ${SRCS_DIR}/ft_strlen.c \
					  ${SRCS_DIR}/ft_strmapi.c \
					  ${SRCS_DIR}/ft_strncmp.c \
					  ${SRCS_DIR}/ft_strnstr.c \
					  ${SRCS_DIR}/ft_strrchr.c \
					  ${SRCS_DIR}/ft_strlcat.c \
					  ${SRCS_DIR}/ft_strtrim.c \
					  ${SRCS_DIR}/ft_substr.c \
					  ${SRCS_DIR}/ft_tolower.c \
					  ${SRCS_DIR}/ft_toupper.c

B_DIR				= ${BONUS_DIR}/ft_lstadd_back_bonus.c \
					  ${BONUS_DIR}/ft_lstadd_front_bonus.c \
					  ${BONUS_DIR}/ft_lstclear_bonus.c \
					  ${BONUS_DIR}/ft_lstdelone_bonus.c \
					  ${BONUS_DIR}/ft_lstiter_bonus.c \
					  ${BONUS_DIR}/ft_lstlast_bonus.c \
					  ${BONUS_DIR}/ft_lstmap_bonus.c \
					  ${BONUS_DIR}/ft_lstnew_bonus.c \
					  ${BONUS_DIR}/ft_lstsize_bonus.c

SRCS_DIR			= .
BONUS_DIR			= .
HEADERS				= libft.h

OBJECTS				= ${SRCS:.c=.o}
B_OBJECTS			= ${B_DIR:.c=.o}

RM					= rm -f
FLAGS				= -Wall -Wextra -Werror

all: 				${NAME}

${NAME}:	${OBJECTS} $(addprefix $(PATHINC), ${HEADERS})
	ar rc ${NAME} ${OBJECTS}
	ranlib ${NAME}

bonus:				${B_OBJECTS} ${HEADERS}
	ar rc ${NAME} ${B_OBJECTS}
	ranlib ${NAME}

.c.o:
	gcc -o $@ -c $< $(FLAGS) -I $(PATHINC)

clean:
	${RM} ${OBJECTS} ${B_OBJECTS}

fclean:		clean
	${RM} ${NAME} ${B_OBJECTS}

re:			fclean all

.PHONY: all clean fclean re bonus
