#include <stdlib.h>
#include <stdio.h>



struct Ball {
	double x, y;
	double vx, vy;
};

struct Ball ball = {.x=0, .y=10, .vx=1, .vy=0};



/*
 * Calculate the position and velocity for the ball after a timestep tdelta
 */
void
moveball(double tdelta, double g, double f)
{
	ball.x += ball.vx * tdelta;
	ball.y += ball.vy * tdelta;
	if (ball.y < 0) {  // bounce!
		ball.y = -ball.y;
		ball.vy = -ball.vy * f;
	}
	ball.vy -= g*tdelta;
	// ball.vx doesn't change, unless we'd include air resistance
	// or ground friction

	return ;
}



int main()
{
	double tdelta = 0.001;
	double g = 9.8;
	double f = 0.9;
	double stop = 10;
	double t = 0;
	while (t < stop) {
		t += tdelta;
		moveball(tdelta, g, f);
		printf("%f  %f  %f\n", t, ball.x, ball.y);
	}

	return EXIT_SUCCESS;
}
