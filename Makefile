# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 15:07:13 by cyrillef          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2017/12/15 17:39:30 by cfrouin          ###   ########.fr        #
=======
#    Updated: 2017/12/15 15:48:09 by kda-silv         ###   ########.fr        #
>>>>>>> 499acdbf3cc7eb36a8dee5b37b43882691d8bf34
#                                                                              #
# **************************************************************************** #

GCC					=	gcc

NAME_ASM			=	asm

NAME_COREWAR		=	corewar

SRCS_ASM_DIR		=	srcs/srcs_asm/

SRCS_ASM			=	main.c \
						op.c \
						error.c \
						parsing_champ.c \
						do_cor.c

SRCS_ASM_FULL		=	$(addprefix $(SRCS_ASM_DIR), $(SRCS_ASM))

SRCS_COREWAR_DIR	=	srcs/srcs_corewar/

SRCS_COREWAR		=	main.c \
						init_data.c \
						read_champions.c \
						init_processes.c \
						init_map.c \
						number_to_hex_str.c \
						vm.c \
						vm_check_live.c \
						error.c

SRCS_COREWAR_FULL	=	$(addprefix $(SRCS_COREWAR_DIR), $(SRCS_COREWAR))

OBJS_ASM			=	$(SRCS_ASM_FULL:.c=.o)

OBJS_COREWAR		=	$(SRCS_COREWAR_FULL:.c=.o)

CFLAGS				=	-Wall -Wextra -I./includes/

all:				libft $(NAME_ASM) $(NAME_COREWAR)

%.o : %.c
					@gcc -g -o $@ -c $< $(CFLAGS)
					@echo "\033[K\033[34mCorewar :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"

$(NAME_ASM):		$(OBJS_ASM)
					@$(GCC) $(OBJS_ASM) -o $(NAME_ASM) -L./libs/libft -lft
					@echo "\033[K\033[32m===========COREWAR==============\033[0m"
					@echo "\033[34mCompiling\033[0m" [ $(NAME_ASM) ] "\033[K\033[32mSuccessful\033[00m"
					@echo "\033[32m================================\033[00m"

$(NAME_COREWAR):	$(OBJS_COREWAR)
					@$(GCC) $(OBJS_COREWAR) -o $(NAME_COREWAR) -L./libs/libft -lft
					@echo "\033[K\033[32m===========COREWAR==============\033[0m"
					@echo "\033[34mCompiling\033[0m" [ $(NAME_COREWAR) ] "\033[K\033[32mSuccessful\033[00m"
					@echo "\033[32m================================\033[00m"

libft:
					@make -C libs/libft

clean:
					@rm -f $(OBJS_ASM) $(OBJS_COREWAR)
					@echo "\033[K\033[31m===========COREWAR===========\033[0m"
					@echo "\033[31mCleaning\033[00m  " [ "*.o" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"
					@make -C libs/libft clean

rclean:
					@rm -f $(OBJS_ASM) $(OBJS_COREWAR)
					@echo "\033[K\033[31m===========COREWAR===========\033[0m"
					@echo "\033[31mCleaning\033[00m  " [ "*.o" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"

fclean:				clean
					@rm -f $(NAME_ASM) $(NAME_COREWAR)
					@echo "\033[K\033[31m===========COREWAR===========\033[0m"
					@echo "\033[31mRemoving\033[00m  " [ "asm" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"
					@echo "\033[K\033[31m===========COREWAR===========\033[0m"
					@echo "\033[31mRemoving\033[00m" [ "corewar" ] "\033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"
					@make -C libs/libft fclean

rfclean:			rclean
					@rm -f $(NAME_ASM) $(NAME_COREWAR)
					@echo "\033[K\033[31m===========COREWAR===========\033[0m"
					@echo "\033[31mRemoving\033[00m  " [ "asm" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"
					@echo "\033[K\033[31m===========COREWAR===========\033[0m"
					@echo "\033[31mRemoving\033[00m" [ "corewar" ] "\033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"

re:					fclean all

ren:				rfclean all

.PHONY:				all clean fclean re ren
