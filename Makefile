# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 10:19:16 by tpereira          #+#    #+#              #
#    Updated: 2021/08/17 15:07:33 by tpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*************************************PROGRAM**********************************#
SERVER 		= server
CLIENT		= client
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror

all :
	@make -s -C libft
	@gcc -g -Wall -Wextra -Werror ./srcs/server.c libft/libft.a -o $(SERVER)
	@gcc -g -Wall -Wextra -Werror ./srcs/client.c libft/libft.a -o $(CLIENT)
	@printf "\e[38;5;46m✅      Compiled Libft	    ✅ \e[0m\n"
	@printf "\e[38;5;46m✅ Client build successfull ✅ \e[0m\n"
	@printf "\e[38;5;46m✅ Server build successfull ✅ \e[0m\n"

clean :
	@make -s clean -C libft 
	@rm -rf ./srcs/client.o ./srcs/server.o
	@printf "\e[31;5;200m🚮️ 	Clean complete      🚮️\e[0m\n"

fclean : clean
	@make -s fclean -C libft
	@rm -rf $(SERVER) $(CLIENT)

re :	fclean all
bonus:	all

.PHONY: bonus re fclean clean all