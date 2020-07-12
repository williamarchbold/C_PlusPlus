//union can only have one member. 
//if i declare union of four floats, it would only be 4 bytes
//can add functions static functions, but no virtual 
//useful for type punning: class with x,y,z correspond to r, g, b

#include <iostream>

struct Vector2
{
	float x, y;
};

struct Vector4 //really just two Vector2's 
{
	float x, y, z, w;

	Vector2& GetA()
	{
		return *(Vector2*)&x;
	}
};


struct Vector4b
{
	union
	{
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			Vector2 a, b;
		};
	};
};

void PrintVector2(const Vector2& vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
	struct Union
	{
		union
		{
			float a;
			int b;
		};
	};

	Union u;

	u.a = 2.0f;

	//u.b is the byte representation of 2 as a float; took memory that made up float and 
	//interpreted it as an int. type punning. 
	std::cout << u.a << ", " << u.b << std::endl;

	Vector4b vector1 = { 1.0f, 2.0f, 3.0f, 4.0f };
	PrintVector2(vector1.a);
	vector1.z = 500.0f;

	std::cout << "------------" << std::endl;
	PrintVector2(vector1.a);
	PrintVector2(vector1.b);

};
