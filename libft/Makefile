# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 22:20:21 by tpereira          #+#    #+#              #
#    Updated: 2021/07/08 10:05:10 by tpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_PATH = includes
SRCS = $(wildcard ./srcs/*.c)
OBJS =  $(SRCS:.c=.o)
BSRCS = ./ft_lstnew.c ./ft_lstadd_front.c ./ft_lstsize.c ./ft_lstlast.c ./ft_lstadd_back.c ./ft_lstdelone.c             \
        ./ft_lstclear.c ./ft_lstiter.c ./ft_lstmap.c
BOBJS = $(BSRCS:.c=.o)
NAME =  libft.a
SO =    libft.so

.c.o:
	$(CC) -g $(CFLAGS) -c $^ -o $(<:.c=.o) -I $(INC_PATH)
all:        $(NAME)
$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)
clean:
	rm -f $(OBJS) $(BOBJS) *.o
soclean:    clean
	rm -f $(SO)
fclean:     clean
	rm -f $(NAME)
	rm -f $(SO)
re:         fclean all
bonus:
	gcc -Wall -Wextra -Werror -c $(BSRCS)
	ar -rcs $(NAME) $(BOBJS)
so:         $(OBJS) $(BOBJS)
	gcc -shared -o $(SO) $(OBJS) $(BOBJS)

.PHONY: so bonus re fclean soclean clean all
