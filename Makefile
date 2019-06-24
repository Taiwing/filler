############################## COMPILE VAR #####################################

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
#CFLAGS		=	-g
HDIR		=	includes
SRCDIR		=	src
SUB1D		=	libft
HFLAGS		=	-I $(HDIR) -I $(SRCDIR)/$(SUB1D)/$(HDIR)
LIBS		=	$(SRCDIR)/$(SUB1D)/libft.a
NAME		=	yforeau.filler

############################## SOURCES #########################################

PARSERDIR		=	parser
SOLVERDIR		=	solver

SRCC			=	main.c\

PARSERC			=	double_arrays.c\
					filler_parser.c\
					get_arrays.c\
					get_dims.c\
					get_player.c\

SOLVERC			=	filler_solver.c\
					heat_map.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(PARSERC))\
					$(patsubst %.c,%.o,$(SOLVERC))\
					$(patsubst %.c,%.o,$(SRCC))\

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.h	$(SRCDIR)/$(SUB1D)/$(HDIR)
vpath			%.c	$(SRCDIR)/$(PARSERDIR)
vpath			%.c	$(SRCDIR)/$(SOLVERDIR)
vpath			%.c	$(SRCDIR)

############################## BUILD ###########################################

all: $(NAME)

$(NAME): $(SRCDIR)/$(SUB1D)/libft.a $(ODIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,$(ODIR)/%.o,$(OBJ)) $(LIBS)

$(SRCDIR)/$(SUB1D)/libft.a:
	make -C $(SRCDIR)/$(SUB1D)

main.o: double_arrays.h filler_parser.h t_filldata.h filler_solver.h libft.h
double_arrays.o: libft.h double_arrays.h
filler_parser.o: double_arrays.h filler_parser.h t_filldata.h libft.h
get_arrays.o: double_arrays.h t_filldata.h libft.h
get_dims.o: t_filldata.h libft.h
get_player.o: t_filldata.h libft.h
filler_solver.o: t_filldata.h heat_map.h libft.h
heat_map.o: t_filldata.h
%.o: %.c
	@mkdir -p $(ODIR)
	$(CC) -c $(CFLAGS) $< $(HFLAGS) -o $(ODIR)/$@

$(ODIR):
	mkdir -p $@

############################## CLEANUP #########################################

clean:
	rm -rf $(ODIR)
	make -C $(SRCDIR)/$(SUB1D) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
