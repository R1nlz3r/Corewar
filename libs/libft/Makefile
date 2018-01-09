# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/08 16:44:57 by kda-silv          #+#    #+#              #
#    Updated: 2017/12/17 12:48:20 by cfrouin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -I./ -Weverything
NAME	=	libft.a
SRCS	=	ft_printf/ft_printf.c \
			ft_printf/run_printf.c \
			ft_printf/functions.c \
			ft_printf/flags/precision.c \
			ft_printf/flags/flag_zero.c \
			ft_printf/flags/do_flag_zero.c \
			ft_printf/flags/flag_c.c \
			ft_printf/flags/flag_upc.c \
			ft_printf/flags/flag_s.c \
			ft_printf/flags/flag_ups.c \
			ft_printf/flags/flag_ups_next.c \
			ft_printf/flags/flag_d.c \
			ft_printf/flags/flag_ulong.c \
			ft_printf/flags/flag_percent.c \
			ft_printf/flags/flag_length.c \
			ft_printf/flags/flag_u.c \
			ft_printf/flags/flag_o.c \
			ft_printf/flags/flag_x.c \
			ft_printf/flags/flag_upx.c \
			ft_printf/flags/flag_long.c \
			ft_printf/flags/flag_i.c \
			ft_printf/flags/flag_p.c \
			ft_printf/flags/flag_b.c \
			ft_printf/flags/flag_point.c \
			ft_printf/flags/flag_hashtag.c \
			ft_printf/flags/flag_upd.c \
			ft_printf/flags/flag_upu.c \
			ft_printf/flags/flag_upo.c \
			get_next_line.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strdel.c \
			ft_strnew.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_print_from_to.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putnbr_unsigned.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_isupper.c \
			ft_islower.c \
			ft_isnumber.c \
			ft_pow.c \
			ft_abs.c \
			ft_realloc_str.c \
			ft_factorial.c \
			ft_sqrt.c \
			ft_lst_size.c \
			ft_puttab.c \
			ft_puttab_fd.c \
			ft_strlen_char.c \
			ft_intlen.c \
			ft_intlen_unsigned.c \
			ft_putnbr_unsigned.c \
			ft_longlong_to_octal.c \
			ft_longlong_to_hexa.c \
			ft_longlonglen.c \
			ft_putnbr_longlong.c \
			ft_longlonglen_unsigned.c \
			ft_putnbr_longlong_unsigned.c \
			ft_longlong_to_binaire.c \
			ft_convert_bin_to_decimal.c \
			ft_wputchar_mask.c \
			ft_wputchar_write.c \
			ft_wstrlen.c \
			ft_error_close.c \
			ft_error_str.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

%.o : %.c
			@gcc -g -o $@ -c $< $(CFLAGS)
			@echo "\033[K\033[34mLibft :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"

$(NAME):	$(OBJS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "\033[K\033[32m============LIBFT===============\033[0m"
			@echo "\033[34mCompiling\033[0m" [ $(NAME) ] "\033[K\033[32mSuccessful\033[00m"
			@echo "\033[32m================================\033[00m"

clean:
			@$(RM) $(OBJS)
			@echo "\033[K\033[31m============LIBFT============\033[0m"
			@echo "\033[31mCleaning\033[00m  " [ "*.o" ] "  \033[32mComplete\033[00m"
			@echo "\033[K\033[31m=============================\033[0m"

fclean:
			@$(RM) $(NAME)
			@echo "\033[K\033[31m============LIBFT============\033[0m"
			@echo "\033[31mRemoving\033[00m" [ $(NAME) ] "\033[32mComplete\033[00m"
			@echo "\033[K\033[31m=============================\033[0m"

re:			fclean all

.PHONY:		all clean fclean re
