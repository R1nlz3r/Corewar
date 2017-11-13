# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 15:07:13 by cyrillef          #+#    #+#              #
#    Updated: 2017/11/13 15:20:20 by cyrillefrouin    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC					= gcc

NAME_ASM			= asm

NAME_COREWAR		= corewar

SRCS_ASM_DIR		= srcs/srcs_asm/

SRCS_ASM			= main.c

SRCS_ASM_FULL		= $(addprefix $(SRCS_ASM_DIR), $(SRCS_ASM))

SRCS_COREWAR_DIR	= srcs/srcs_corewar/

SRCS_COREWAR		= main.c

SRCS_COREWAR_FULL	= $(addprefix $(SRCS_COREWAR_DIR), $(SRCS_COREWAR))

OBJS_ASM			= $(SRCS_ASM_FULL:.c=.o)

OBJS_COREWAR		= $(SRCS_COREWAR_FULL:.c=.o)

CFLAGS				= -Wall -Wextra -I./includes/

all:				$(NAME_ASM) $(NAME_COREWAR)

$(NAME_ASM):		$(OBJS_ASM)
					$(GCC) $(OBJS_ASM) -o $(NAME_ASM)

$(NAME_COREWAR):	$(OBJS_COREWAR)
					$(GCC) $(OBJS_COREWAR) -o $(NAME_COREWAR)

clean:
					rm -f $(OBJS_ASM) $(OBJS_COREWAR)

fclean:				clean
					rm -f $(NAME_ASM) $(NAME_COREWAR)

re:					fclean re

.PHONY:				all clean fclean re
