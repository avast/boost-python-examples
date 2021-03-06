// boost-python-examples.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include <boost/python.hpp>


class Circle
{
public:
	Circle() {}
	Circle(float radius) : radius(radius) {}
	const float pi{ 3.14f };
	float radius;
	float get_area() { return this->pi * std::pow(this->radius, 2); };
};

class Cylinder : public Circle
{
private:
	float height;
public:
	Cylinder(float radius, float height) : height(height) { this->radius = radius; }
	void set_height(float f) { this->height = f; }
	float get_height() { return this->height; }
	float get_area() { return 2 * this->pi * this->radius * (this->radius + this->height); }
	float get_volume() { return this->pi * std::pow(this->radius, 2) * this->height; }
	PyObject* get_values_as_dict() {
		boost::python::dict d;
		d[std::wstring(L"area")] = this->get_area();
		d[std::wstring(L"volume")] = this->get_volume();
		return boost::python::incref(boost::python::object(d).ptr());
	};
};


BOOST_PYTHON_MODULE(my_module)
{
	using namespace boost::python;

	class_<Circle>("Circle", init<float>())
		.def_readonly("pi", &Circle::pi)
		.def_readwrite("radius", &Circle::radius)
		.def("get_area", &Circle::get_area)
		;

	class_<Cylinder, bases<Circle> >("Cylinder", init<float, float>((boost::python::arg("radius"), boost::python::arg("height"))))
		.add_property("height", &Cylinder::get_height, &Cylinder::set_height)
		.def("get_area", &Cylinder::get_area)
		.def("get_metrics_dict", &Cylinder::get_values_as_dict)
		;
}
