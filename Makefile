# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 10:19:16 by tpereira          #+#    #+#              #
#    Updated: 2021/08/11 12:00:53 by tpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*************************************PROGRAM**********************************#
SERVER 		= server
CLIENT		= client
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
HEADER		= ./includes/minitalk.h
SERVER_SRCS = $(wildcard ./srcs/*server.c)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_SRCS = $(wildcard ./srcs/*client.c)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
#*************************************LIBFT*************************************#
LIB_SRCS	= mv $(LIB_NAME)/libft.a ./$(NAME)
LIB_OBJS	= $(LIB_SRCS:.c=.o)
LIB_NAME	= libft
LIB_HEADER	= -I libft/includes
INC_PATH 	= includes $(LIB_HEADER)
SO 			= libft.so

.c.o:
	$(CC) -g $(CFLAGS) -c $^ -o $(<:.c=.o) -I $(INC_PATH)

all:	$(LIB_NAME) $(SERVER) $(CLIENT)

$(SERVER):	$(SERVER_OBJS) $(HEADER)
	make -C $(LIB_NAME)
	mv $(LIB_NAME)/libft.a ./$(SERVER)
	ar -rcs $(SERVER) $(SERVER_OBJS)
	@printf "\e[38;5;46m./$@ Server build successfull ✅ \e[0m\n"

$(CLIENT):	$(CLIENT_OBJS) $(HEADER)
	make -C $(LIB_NAME)
	mv $(LIB_NAME)/libft.a ./$(CLIENT)
	ar -rcs $(CLIENT) $(CLIENT_OBJS)
	@printf "\e[38;5;46m./$@ Client build successfull ✅ \e[0m\n"

clean:
	make clean -C $(LIB_NAME)/
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	@printf "\e[38;5;200m❌ Deleted objects ❌\e[0m\n"
fclean:     clean
	rm -f $(CLIENT) $(SERVER)
re:         fclean all
bonus:		all
so:         $(SERVER_OBJS) $(CLIENT_OBJS)
	gcc -shared -o $(SO) $(SERVER_OBJS) $(CLIENT_OBJS)

.PHONY: bonus re fclean clean all