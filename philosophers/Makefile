# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 19:45:15 by ppeapod           #+#    #+#              #
#    Updated: 2021/12/30 19:45:18 by ppeapod          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philosophers
NAME_BONUS	= philosophers_bonus

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
RM			= rm -f

INCS		= -I include

SRC		=	philo.c dop_funks.c philo_init.c
SRC_BONUS	=	philo_bonus.c dop_funks_bonus.c philo_init_bonus.c

SRCS		=	$(SRC)
OBJS		=	$(SRCS:.c=.o)

SRCS_BONUS	=	$(SRC_BONUS)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)


.c.o :
	$(CC) $(CFLAGS) -o $@ -c $?

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : clean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) -o $(NAME_BONUS) $(OBJS_BONUS)

PHONY	: all clean fclean re bonus
