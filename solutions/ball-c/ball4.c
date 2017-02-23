#include <stdlib.h>
#include <stdio.h>



struct Ball {
	double x, y;
	double vx, vy;
};


/*
 * Calculate the position and velocity for the ball after a timestep tdelta
 */
void
moveball(struct Ball *ball, double tdelta, double g, double f)
{
	ball->x += ball->vx * tdelta;
	ball->y += ball->vy * tdelta;
	if (ball->y < 0) {  // bounce!
		ball->y = -ball->y;
		ball->vy = -ball->vy * f;
	}
	ball->vy -= g*tdelta;
	// ball->vx doesn't change, unless we'd include air resistance
	// or ground friction

	return ;
}



int main()
{
	struct Ball ball = {.x=0, .y=10, .vx=1, .vy=0};
	double *timestamps = NULL;
	double *xpos = NULL;
	double *ypos = NULL;

	// We're going to ask for input, but initialize these
	// variables anyway;better safe than sorry
	double tdelta = 0.001;
	double g = 9.8;
	double f = 0.9;
	double stop = 10;

	printf("Gravitational acceleration: ");
	int nitems = scanf("%lf", &g);
	if (nitems != 1) {
		fprintf(stderr, "Incorrect input!\n");
		return EXIT_FAILURE;
	}
	printf("Bounce efficiency: ");
	nitems = scanf("%lf", &f);
	if (nitems != 1) {
		fprintf(stderr, "Incorrect input!\n");
		return EXIT_FAILURE;
	}

	printf("Duration: ");
	nitems = scanf("%lf", &stop);
	if (nitems != 1) {
		fprintf(stderr, "Incorrect input!\n");
		return EXIT_FAILURE;
	}
	printf("Time increment: ");
	nitems = scanf("%lf", &tdelta);
	if (nitems != 1) {
		fprintf(stderr, "Incorrect input!\n");
		return EXIT_FAILURE;
	}

	long long n = (long long) (stop / tdelta) + 1;
	if (n <= 0) {
		fprintf(stderr, "Not enough simulation time\n");
		return EXIT_FAILURE;
	}
	timestamps = malloc(n * sizeof *timestamps);
	xpos = malloc(n * sizeof *ypos);
	ypos = malloc(n * sizeof *xpos);
	if (timestamps == NULL || xpos == NULL || ypos == NULL) {
		fprintf(stderr, "Out of memory\n");
		return EXIT_FAILURE;
	}

	double t = 0;
	for (long long i = 0; i < n; ++i) {
		timestamps[i] = t;
		xpos[i] = ball.x;
		ypos[i] = ball.y;
		moveball(&ball, tdelta, g, f);
		t += tdelta;
	}

	for (long long i = 0; i < n; ++i) {
		printf("%f  %f  %f\n", timestamps[i], xpos[i], ypos[i]);
	}

	free(timestamps);
	free(xpos);
	free(ypos);

	return EXIT_SUCCESS;
}
