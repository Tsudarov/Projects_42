#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgerbaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/05 21:29:17 by cgerbaud          #+#    #+#              #
#    Updated: 2018/02/27 19:47:57 by cgerbaud         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	rt

INCLUDES	=	-I includes -I includes/core -I includes/scene -I includes/calcs -I includes/objects -I includes/parser -I minilibx_macos -I includes/loadbar

LIBS		=	-L minilibx_macos -lmlx -framework OpenGL -framework AppKit

SRCPATH		=	src/

OBJPATH		=	obj/

SRCS		=	main.c															\
				calcs/calcs.c													\
				calcs/calcs_reals.c												\
				calcs/calcs_quadratic.c											\
				calcs/color.c													\
				calcs/color_operators.c											\
				calcs/intersection.c											\
				calcs/init_optics.c												\
				calcs/optics.c													\
				calcs/vector.c													\
				calcs/vector_eqoperators.c										\
				calcs/vector_operators.c										\
				calcs/vector_unit_vector.c										\
				core/calculate_lightning.c										\
				core/calculate_matte.c											\
				core/calculate_refraction.c										\
				core/is_on_los.c												\
				core/mlx_mgr.c													\
				core/mlx_prints.c												\
				core/objects_mgr.c												\
				core/raytrace.c													\
				core/raytrace_misc.c											\
				core/trace_ray.c												\
				objects/binary_operator.c										\
				objects/binary_operator_rotate_x.c								\
				objects/binary_operator_rotate_y.c								\
				objects/binary_operator_rotate_z.c								\
				objects/camera.c												\
				objects/chessboard.c											\
				objects/complement.c											\
				objects/complement_operations.c									\
				objects/cone.c													\
				objects/cuboid.c												\
				objects/cuboid_check_x.c										\
				objects/cuboid_check_y.c										\
				objects/cuboid_check_z.c										\
				objects/cylinder.c												\
				objects/difference.c											\
				objects/intersection_o.c										\
				objects/light.c													\
				objects/object.c												\
				objects/solid_object.c											\
				objects/solid_object_reorientable.c								\
				objects/solid_object_reorientable_append_all_intersections.c	\
				objects/solid_object_reorientable_camera.c						\
				objects/solid_object_reorientable_rotate.c						\
				objects/sphere.c												\
				objects/spheroid.c												\
				objects/strings.c												\
				objects/thinring.c												\
				objects/transformation_stack.c									\
				objects/transformation_stack_apply.c							\
				objects/union.c													\
				loadbar/loadbar.c												\
				loadbar/ft_itoa.c												\
				scene/scene.c													\
				scene/scene_list.c												\
				scene/get_current_scene.c										\
				parser/exctract.c												\
				parser/exctract_value_same_level.c								\
				parser/parser.c													\
				parser/read.c

SRC			=	$(addprefix $(SRCPATH), $(SRCS))

OBJ			=	$(patsubst $(SRCPATH)%.c, $(OBJPATH)%.o, $(SRC))

CFLAGS		+=	-Wall -Wextra -Werror $(INCLUDES)

CC			=	gcc

all: $(NAME)

$(OBJ): | $(OBJPATH)

$(NAME): $(OBJ)
	$(MAKE) -C minilibx_macos
	$(CC) $(CFLAGS) $(LIBS) -o $(NAME) $(OBJ)

$(OBJPATH):
	mkdir -p $(OBJPATH)core $(OBJPATH)scene $(OBJPATH)calcs $(OBJPATH)objects $(OBJPATH)parser $(OBJPATH)loadbar

clean:
	$(MAKE) -C minilibx_macos clean
	rm -rf $(OBJPATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

minilibx:
	$(MAKE) -C minilibx_macos

$(OBJPATH)%.o: $(SRCPATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re minilibx
