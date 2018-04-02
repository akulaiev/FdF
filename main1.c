#include "fdf.h"
#include <stdio.h>

static t_minlx	manipulate_window()
{
	t_minlx	win;

	win.mlx_p = mlx_init();
	win.mlx_nw = mlx_new_window(win.mlx_p, 713, 713, "test_window");
	return (win);
}

int		main(void)
{
	t_minlx		win;

	t_dot a;
	t_dot b;
	t_dot c;
	t_dot d;


	a.x = 10;
	a.y = 10;
	a.z = 0;

	b.x = 100;
	b.y = 10;
	b.z = 0;

	c.x = 10;
	c.y = 100;
	c.z = 0;

	d.x = 100;
	d.y = 100;
	d.z = 0;

	win = manipulate_window();
	win.col = 0xffffff;
	mlx_key_hook(win.mlx_nw, key_react, (void*)0);

	draw_a_line(win, a, b);
	draw_a_line(win, a, c);
	draw_a_line(win, c, d);
	draw_a_line(win, d, b);

	a.x = 300;
	a.y = 10;
	a.z = 10;

	b.x = 400;
	b.y = 10;
	b.z = 0;

	c.x = 300;
	c.y = 100;
	c.z = 0;

	d.x = 400;
	d.y = 100;
	d.z = 0;

	draw_a_line(win, a, b);
	draw_a_line(win, a, c);
	draw_a_line(win, c, d);
	draw_a_line(win, d, b);

	mlx_loop(win.mlx_p);
}