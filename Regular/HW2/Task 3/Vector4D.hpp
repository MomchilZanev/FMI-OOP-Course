#pragma once

class Vector4D
{
public:
    Vector4D();
    Vector4D(double, double, double, double);

    double& operator[](unsigned int index);
    Vector4D operator+(const Vector4D& rhs) const;
    Vector4D& operator+=(const Vector4D& rhs);
    Vector4D operator-(const Vector4D& rhs) const;
    Vector4D& operator-=(const Vector4D& rhs);
    Vector4D operator*(const Vector4D& rhs) const;
    Vector4D operator*(const double& coef) const;
    Vector4D& operator*=(const Vector4D& rhs);
    Vector4D& operator*=(const double& coef);
    Vector4D operator/(const Vector4D& rhs) const;
    Vector4D operator/(const double& coef) const;
    Vector4D& operator/=(const Vector4D& rhs);
    Vector4D& operator/=(const double& coef);

    bool operator==(const Vector4D& rhs) const;
    bool operator!=(const Vector4D& rhs) const;
    bool operator<(const Vector4D& rhs) const;
    bool operator<=(const Vector4D& rhs) const;
    bool operator>(const Vector4D& rhs) const;
    bool operator>=(const Vector4D& rhs) const;
    bool operator!() const;
    Vector4D operator-() const;
private:
    bool lesserOrEqual(const Vector4D& rhs) const;
    bool greaterOrEqual(const Vector4D& rhs) const;

    double vector[4];
};