#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>


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

		std::cout << "Gravitational acceleration: ";
		std::cin >> g;
		std::cout << "Bounce efficiency: ";
		std::cin >> f;

		std::cout << "Duration: ";
		std::cin >> stop;
		std::cout << "Time increment: ";
		std::cin >> tdelta;

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
				std::cout << timestamps[i] << "  ";
				std::cout << xpos[i] << "  " << ypos[i] << std::endl;
		}

		return EXIT_SUCCESS;
}
