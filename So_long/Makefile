INCLUDES = -I/usr/inc -Imlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
 
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)