#include <iostream>
#include <string>
#include <vector>

//called standard template library because you can template it into everything; underlying data type that template holds are up to you
//new array with adquate size copies contents from old array and then deletes old, but not always the best

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		: x(x), y(y), z(z)
	{
	}

	Vertex(const Vertex& vertex)
		: x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied!" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

void Function(const std::vector<Vertex>& vertices) //make sure you're only passing by const reference. don't want to copy unless absolutely have to!
{

}

int main()
{
	std::vector<Vertex> vertices; //in java can't pass primitive data types, would have to use Integer class, but in C++ you can
	vertices.push_back({ 1,2,3 });
	vertices.push_back({ 4,5,6 }); //prints copied twice because vector needs to resize and both elements are recopied. wasteful!

	for (int i = 0; i < vertices.size(); i++)
	{
		std::cout << vertices[i] << std::endl;
	}


	for (Vertex& v : vertices) //ampersande to not needlessly copy vertices
	{
		std::cout << v << std::endl;
	}

	vertices.erase(vertices.begin() + 1);

	vertices.push_back({ 4,5,6 });
	vertices.push_back(Vertex(7, 9, 9));

	std::vector<Vertex> vertices2;

	std::cout << "Reserving space for new vector " << std::endl;
	vertices2.reserve(3); //makes sure we have enough memory
	vertices2.push_back(Vertex(1, 2, 3)); //still copies because it builds the Vertex in main then copies it to the vector
	vertices2.push_back(Vertex(4, 5, 6));
	vertices2.push_back(Vertex(7, 8, 9));

	std::vector<Vertex> vertices3;

	vertices3.reserve(3);
	vertices3.emplace_back(Vertex(1, 2, 3)); //not a single copy done because emplace_back puts Vertex directly into vector first skipping main
	vertices3.emplace_back(Vertex(4, 5, 6));


	std::cin.get();
}