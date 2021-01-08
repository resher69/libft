# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 11:11:01 by agardet           #+#    #+#              #
#    Updated: 2021/01/08 13:22:07 by agardet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_strlen.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_memchr.c\
			ft_atoi.c\
			ft_memccpy.c\
			ft_memcmp.c\
			ft_memmove.c\
			ft_strncmp.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_calloc.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strnstr.c\
			ft_strdup.c\
			ft_strcpy.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_memmove.c\
			ft_strcat.c\
			ft_strjoin.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_substr.c\
			ft_strtrim.c\
			ft_itoa.c\
			ft_split.c\
			ft_strncpy.c\
			\
			ft_lstadd_back.c\
			ft_lstadd_front.c\
			ft_lstdelone.c\
			ft_lstlast.c\
			ft_lstnew.c\
			ft_lstsize.c\


OBJS	=	$(SRCS:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

NAME	=	libft.a

$(NAME):	$(OBJS)
			ar -rc $(NAME) $(OBJS)
			ranlib $(NAME)

HEADER = libft.h

%.o:		%.c
			gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

all:		$(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
