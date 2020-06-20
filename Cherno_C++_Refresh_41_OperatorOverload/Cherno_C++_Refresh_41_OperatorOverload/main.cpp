#include <iostream>
#include <string>

struct Vector2  //x and y two component vector
{
	float x, y;

	Vector2(float a, float b)
		: x(a), y(b) {}
	Vector2 Add(const Vector2& other) const //not going to modify class
	{
		return Vector2(x + other.x, y + other.y);
	}
	Vector2 Multiply(const Vector2& other) const //not going to modify class
	{
		return Vector2(x * other.x, y * other.y);
	}
	Vector2 operator+(const Vector2& other) const
	{
		return Add(other);
	}
	Vector2 operator*(const Vector2& other) const
	{
		return Multiply(other);
	}

	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	stream << other.x << ", " << other.y;
	return stream;
}

int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 power_up(1.2f, 1.2f);

	Vector2 result = position.Add(speed);
	Vector2 result2 = result.Multiply(result); //in java this is your only choice but c++ has operator overload

	Vector2 result3 = position + speed * power_up;

	if (result2 == result3) {
		std::cout << "equal!" << std::endl;
	}

	std::cout << result3 << std::endl;

	std::cin.get();
}