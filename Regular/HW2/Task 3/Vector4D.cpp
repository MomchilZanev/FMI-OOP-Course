#include "Vector4D.hpp"

Vector4D::Vector4D() : vector()
{ }

Vector4D::Vector4D(double a, double b, double c, double d)
{
	this->vector[0] = a;
	this->vector[1] = b;
	this->vector[2] = c;
	this->vector[3] = d;
}

double& Vector4D::operator[](unsigned int index)
{
	return this->vector[index];
}

Vector4D Vector4D::operator+(const Vector4D& rhs) const
{
	double a = this->vector[0] + rhs.vector[0];
	double b = this->vector[1] + rhs.vector[1];
	double c = this->vector[2] + rhs.vector[2];
	double d = this->vector[3] + rhs.vector[3];
	return Vector4D(a, b, c, d);
}

Vector4D& Vector4D::operator+=(const Vector4D& rhs)
{
	this->vector[0] += rhs.vector[0];
	this->vector[1] += rhs.vector[1];
	this->vector[2] += rhs.vector[2];
	this->vector[3] += rhs.vector[3];
	return *this;
}

Vector4D Vector4D::operator-(const Vector4D& rhs) const
{
	double a = this->vector[0] - rhs.vector[0];
	double b = this->vector[1] - rhs.vector[1];
	double c = this->vector[2] - rhs.vector[2];
	double d = this->vector[3] - rhs.vector[3];
	return Vector4D(a, b, c, d);
}

Vector4D& Vector4D::operator-=(const Vector4D& rhs)
{
	this->vector[0] -= rhs.vector[0];
	this->vector[1] -= rhs.vector[1];
	this->vector[2] -= rhs.vector[2];
	this->vector[3] -= rhs.vector[3];
	return *this;
}

Vector4D Vector4D::operator*(const Vector4D& rhs) const
{
	double a = this->vector[0] * rhs.vector[0];
	double b = this->vector[1] * rhs.vector[1];
	double c = this->vector[2] * rhs.vector[2];
	double d = this->vector[3] * rhs.vector[3];
	return Vector4D(a, b, c, d);
}

Vector4D Vector4D::operator*(const double& coef) const
{
	double a = this->vector[0] * coef;
	double b = this->vector[1] * coef;
	double c = this->vector[2] * coef;
	double d = this->vector[3] * coef;
	return Vector4D(a, b, c, d);
}

Vector4D& Vector4D::operator*=(const Vector4D& rhs)
{
	this->vector[0] *= rhs.vector[0];
	this->vector[1] *= rhs.vector[1];
	this->vector[2] *= rhs.vector[2];
	this->vector[3] *= rhs.vector[3];
	return *this;
}

Vector4D& Vector4D::operator*=(const double& coef)
{
	this->vector[0] *= coef;
	this->vector[1] *= coef;
	this->vector[2] *= coef;
	this->vector[3] *= coef;
	return *this;
}

Vector4D Vector4D::operator/(const Vector4D& rhs) const
{
	double a = this->vector[0] / rhs.vector[0];
	double b = this->vector[1] / rhs.vector[1];
	double c = this->vector[2] / rhs.vector[2];
	double d = this->vector[3] / rhs.vector[3];
	return Vector4D(a, b, c, d);
}

Vector4D Vector4D::operator/(const double& coef) const
{
	double a = this->vector[0] / coef;
	double b = this->vector[1] / coef;
	double c = this->vector[2] / coef;
	double d = this->vector[3] / coef;
	return Vector4D(a, b, c, d);
}

Vector4D& Vector4D::operator/=(const Vector4D& rhs)
{
	this->vector[0] /= rhs.vector[0];
	this->vector[1] /= rhs.vector[1];
	this->vector[2] /= rhs.vector[2];
	this->vector[3] /= rhs.vector[3];
	return *this;
}

Vector4D& Vector4D::operator/=(const double& coef)
{
	this->vector[0] /= coef;
	this->vector[1] /= coef;
	this->vector[2] /= coef;
	this->vector[3] /= coef;
	return *this;
}

bool Vector4D::operator==(const Vector4D& rhs) const
{
	bool result = true;
	this->vector[0] != rhs.vector[0] ? result = false : 0;
	this->vector[1] != rhs.vector[1] ? result = false : 0;
	this->vector[2] != rhs.vector[2] ? result = false : 0;
	this->vector[3] != rhs.vector[3] ? result = false : 0;
	return result;
}

bool Vector4D::operator!=(const Vector4D& rhs) const
{
	return !(*this == rhs);
}

bool Vector4D::operator<(const Vector4D& rhs) const
{
	if (*this == rhs)
	{
		return false;
	}
	
	return this->lesserOrEqual(rhs);
}

bool Vector4D::operator<=(const Vector4D& rhs) const
{
	return this->lesserOrEqual(rhs);
}

bool Vector4D::operator>(const Vector4D& rhs) const
{
	if (*this == rhs)
	{
		return false;
	}
	
	return this->greaterOrEqual(rhs);
}

bool Vector4D::operator>=(const Vector4D& rhs) const
{
	return this->greaterOrEqual(rhs);
}

bool Vector4D::operator!() const
{
	return 
		this->vector[0] == 0 && 
		this->vector[1] == 0 && 
		this->vector[2] == 0 && 
		this->vector[3] == 0;
}

Vector4D Vector4D::operator-() const
{
	double a = -this->vector[0];
	double b = -this->vector[1];
	double c = -this->vector[2];
	double d = -this->vector[3];
	return Vector4D(a, b, c, d);
}

bool Vector4D::lesserOrEqual(const Vector4D& rhs) const
{
	bool result = true;
	this->vector[0] > rhs.vector[0] ? result = false : 0;
	this->vector[1] > rhs.vector[1] ? result = false : 0;
	this->vector[2] > rhs.vector[2] ? result = false : 0;
	this->vector[3] > rhs.vector[3] ? result = false : 0;
	return result;
}

bool Vector4D::greaterOrEqual(const Vector4D& rhs) const
{
	bool result = true;
	this->vector[0] < rhs.vector[0] ? result = false : 0;
	this->vector[1] < rhs.vector[1] ? result = false : 0;
	this->vector[2] < rhs.vector[2] ? result = false : 0;
	this->vector[3] < rhs.vector[3] ? result = false : 0;
	return result;
}