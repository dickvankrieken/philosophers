NAME = philo

SRCS = main.c time.c utils.c threads.c time.c act.c error.c

SRC_FILES = $(addprefix $(SRCDIR)/,$(SRCS))

SRCDIR = srcs

OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

OBJDIR = objs

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -g -fsanitize=address -o $@ $^

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -g -fsanitize=address $^ -o $@

clean:
	rm -f $(NAME)

fclean: clean
	rm -rf $(NAME) $(OBJDIR)

re: fclean
	$(MAKE)
