NAME	:=	cvector.a

CC		:=	cc
CFLAGS	:=	-Wall -Werror -Wextra

FILES	:=	vctrassign.c \
			vctrat.c \
			vctrat_const.c \
			vctrbck.c \
			vctrbck_const.c \
			vctrclear.c \
			vctrcpcty.c \
			vctrcpy.c \
			vctrdata.c \
			vctrdata_const.c \
			vctrdup.c \
			vctrerase.c \
			vctrerase_range.c \
			vctrfrnt.c \
			vctrfrnt_const.c \
			vctrinsert.c \
			vctrmpty.c \
			vctrmxsize.c \
			vctrnew.c \
			vctrpop_back.c \
			vctrpop_front.c \
			vctrprint.c \
			vctrpush_back.c \
			vctrpush_front.c \
			vctrresize.c \
			vctrrm.c \
			vctrrsrv.c \
			vctrshrnk.c \
			vctrsize.c \
			_vector_need_growth.c \
			_vector_need_shrink.c \
			_vector_offset.c \
			_vector_resize.c 

SRCS	:=	$(addprefix src/, $(FILES))

OBJS	:=	$(addprefix obj/, $(FILES:.c=.o))

INCS	:=	-I inc

all: ${NAME}

obj:
	@mkdir -p obj

${NAME}: ${OBJS}
	@echo "Creating: $(NAME)"
	@ar rcs ${NAME} ${OBJS}

obj/%.o: src/%.c | obj
	@echo "Compiling: $(notdir $<)"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@echo "Removing: $(NAME:.a=) object files"
	@rm -rf obj

fclean: clean
	@echo "Removing: $(NAME)"
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re obj
