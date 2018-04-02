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
	t_dot e;
	t_dot f;
	t_dot g;
	t_dot h;

	a.x = 10;
	a.y = 10;
	a.z = 10;

	b.x = 100;
	b.y = 10;
	b.z = 10;

	c.x = 10;
	c.y = 100;
	c.z = 10;

	d.x = 10;
	d.y = 10;
	d.z = 100;

	e.x = 100;
	e.y = 100;
	e.z = 10;

	f.x = 10;
	f.y = 100;
	f.z = 100;

	g.x = 100;
	g.y = 10;
	g.z = 100;

	h.x = 100;
	h.y = 100;
	h.z = 100;

	win = manipulate_window();
	win.col = 0xffffff;
	mlx_key_hook(win.mlx_nw, key_react, (void*)0);

	draw_a_line(win, a, b);
	draw_a_line(win, a, c);
	draw_a_line(win, a, d);
	draw_a_line(win, c, e);
	draw_a_line(win, b, e);
	draw_a_line(win, f, c);
	draw_a_line(win, f, d);
	draw_a_line(win, d, g);
	draw_a_line(win, b, g);
	draw_a_line(win, f, h);
	draw_a_line(win, e, h);
	draw_a_line(win, g, h);

	a.x = 250;
	a.y = 250;
	a.z = 150;

	b.x = 400;
	b.y = 250;
	b.z = 150;

	c.x = 250;
	c.y = 400;
	c.z = 150;

	d.x = 250;
	d.y = 250;
	d.z = 400;

	e.x = 400;
	e.y = 400;
	e.z = 150;

	f.x = 250;
	f.y = 400;
	f.z = 400;

	g.x = 400;
	g.y = 250;
	g.z = 400;

	h.x = 400;
	h.y = 400;
	h.z = 400;

	win.col = 0x42f4e5;
	draw_a_line(win, a, b);
	draw_a_line(win, a, c);
	draw_a_line(win, a, d);
	draw_a_line(win, c, e);
	draw_a_line(win, b, e);
	draw_a_line(win, f, c);
	draw_a_line(win, f, d);
	draw_a_line(win, d, g);
	draw_a_line(win, b, g);
	draw_a_line(win, f, h);
	draw_a_line(win, e, h);
	draw_a_line(win, g, h);

	mlx_loop(win.mlx_p);
}