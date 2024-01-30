ifndef SETTINGS_MK
	SETTINGS_MK := 1

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::TARGET::

NAME	=	fdf

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOURCE::

SRC		=	$Sfdf_bresenham.c \
			$Sfdf.c \
			$Sfdf_controls.c \
			$Sfdf_init.c \
			$Sfdf_list.c \
			$Sfdf_mods.c \
			$Sfdf_parse.c \
			$Sfdf_print.c \
			$Sfdf_projections.c \
			$Sfdf_utils.c \
			$Sget_next_line.c \
			$Sget_next_line_utils.c


# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COMPILERS::

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

AR		=	ar

ARFLAGS	=	rcs

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LIBRARY::

IS_LIB	= 	true

LIB		= 	$Llibft.a

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::FT_PRINTF::

IS_PTF	= 	true

PTF		= 	$Plibftprintf.a

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::MINILIBX::

IS_MLX	= 	true

MLX		= 	$Mlibmlx_Linux.a

endif