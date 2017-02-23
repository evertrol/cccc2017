#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>


class Ball {
public:
		Ball(double gravity, double efficiency,
			 double xpos=0, double ypos=10,
			 double xvel=1, double yvel=0) :
				x{xpos}, y{ypos},
				g{gravity}, f{efficiency},
				vx{xvel}, vy{yvel} { }
		void move(double tdelta);

public:
		double x, y;
private:
		double g, f;
		double vx, vy;
};


/*
 * Calculate the position and velocity for the ball after a timestep tdelta
 */
void
Ball::move(double tdelta)
{
		x += vx * tdelta;
		y += vy * tdelta;
		if (y < 0) {  // bounce!
				y = -y;
				vy = -vy * f;
		}
		vy -= g*tdelta;
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

		std::cout << "Gravitational acceleration: ";
		std::cin >> g;
		std::cout << "Bounce efficiency: ";
		std::cin >> f;

		std::cout << "Duration: ";
		std::cin >> stop;
		std::cout << "Time increment: ";
		std::cin >> tdelta;

		Ball ball{g, f};

		std::vector<double> timestamps;
		std::vector<double> xpos;
		std::vector<double> ypos;

		double t = 0;
		while (t < stop) {
				timestamps.push_back(t);
				xpos.push_back(ball.x);
				ypos.push_back(ball.y);
				ball.move(tdelta);
				t += tdelta;
		}

		for (size_t i = 0; i < timestamps.size(); ++i) {
				std::cout << timestamps[i] << "  ";
				std::cout << xpos[i] << "  " << ypos[i] << std::endl;
		}

		return EXIT_SUCCESS;
}
