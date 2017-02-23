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
	// We're going to ask for input, but initialize these
	// variables anyway;better safe than sorry
	double tdelta = 0.001;
	double g = 9.8;
	double f = 0.9;
	double stop = 10;
	
	printf("Gravitational acceleration: ");
	int nitems = scanf("%lf", &g);
	if (nitems != 1) {
		fprintf(stderr, "Incorrect input!");
		return EXIT_FAILURE;
	}
	printf("Bounce efficiency: ");
	nitems = scanf("%lf", &f);
	if (nitems != 1) {
		fprintf(stderr, "Incorrect input!");
		return EXIT_FAILURE;
	}

	printf("Duration: ");
	nitems = scanf("%lf", &stop);
	if (nitems != 1) {
		fprintf(stderr, "Incorrect input!");
		return EXIT_FAILURE;
	}
	printf("Time increment: ");
	nitems = scanf("%lf", &tdelta);
	if (nitems != 1) {
		fprintf(stderr, "Incorrect input!");
		return EXIT_FAILURE;
	}
	
	double t = 0;
	while (t < stop) {
		printf("%f  %f  %f\n", t, ball.x, ball.y);
		moveball(tdelta, g, f);
		t += tdelta;
	}

	return EXIT_SUCCESS;
}
