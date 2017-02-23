#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>


class Ball {
public:
		Ball(double gravity, double efficiency,
			 double xpos=0, double ypos=10,
			 double xvel=1, double yvel=0);

		void calculate(double start, double stop, double timestep);
		void print();
		
		std::vector<double> timestamps;
		std::vector<double> xdata;
		std::vector<double> ydata;

private:
		void move(double tdelta);

		double g, f;
		double x, y;
		double vx, vy;
};


Ball::Ball(double gravity, double efficiency,
		   double xpos, double ypos,
		   double xvel, double yvel) :
		g{gravity}, f{efficiency},
		x{xpos}, y{ypos},
		vx{xvel}, vy{yvel}
{
		timestamps = std::vector<double>{};
		xdata = std::vector<double>{};
		xdata = std::vector<double>{};
}


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
}

void
Ball::print()
{
		for (size_t i = 0; i < timestamps.size(); ++i) {
				std::cout << timestamps[i] << "  ";
				std::cout << xdata[i] << "  ";
				std::cout << ydata[i] << std::endl;
		}

}


void
Ball::calculate(double start, double stop, double timestep)
{
		for (double t = start; t < stop; t += timestep) {
				timestamps.push_back(t);
				xdata.push_back(x);
				ydata.push_back(y);
				move(timestep);
		}
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
		ball.calculate(0, stop, tdelta);
		ball.print();

		return EXIT_SUCCESS;
}
