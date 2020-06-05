#pragma once
#include <vector>

namespace graphic {

	struct Sphere {
		double x;
		double y;
		double z;

		double r;
		double g;
		double b;

		double radius;
	};

	struct Camera {
		double x;
		double y;
		double z;

		double lx;
		double ly;
		double lz;
	};

	struct Orders {

		std::vector<Sphere> spheres;

		void push_sphere(double x, double y, double z, double r) noexcept {
			spheres.push_back({x, y, z, 1, 1, 1, r});
		}
		void clear() noexcept {
			spheres.clear();
		}

	};

	void render(const Camera& camera, const Orders& orders) noexcept;
};
