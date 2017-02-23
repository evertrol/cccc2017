#include <cstdlib>
#include <cstdio>
#include <vector>



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
		struct Ball ball = {0, 10, 1, 0};

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

		std::vector<double> timestamps;
		std::vector<double> xpos;
		std::vector<double> ypos;

		double t = 0;
		while (t < stop) {
				timestamps.push_back(t);
				xpos.push_back(ball.x);
				ypos.push_back(ball.y);
				moveball(&ball, tdelta, g, f);
				t += tdelta;
		}

		for (size_t i = 0; i < timestamps.size(); ++i) {
				printf("%f  %f  %f\n", timestamps[i], xpos[i], ypos[i]);
		}

		return EXIT_SUCCESS;
}
