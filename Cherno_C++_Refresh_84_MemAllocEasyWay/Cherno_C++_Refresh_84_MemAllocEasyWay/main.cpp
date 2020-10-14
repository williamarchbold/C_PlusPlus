#include <iostream>
#include <memory>

struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;

	uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size) //overload operator new that returns a void* (memory address)
{
	std::cout << "Allocating " << size << " bytes\n";
	s_AllocationMetrics.TotalAllocated += size;
	return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	std::cout << "Deleting " << size << " bytes\n";
	s_AllocationMetrics.TotalFreed -= size;
	free(memory);
}

struct Object
{
	int x, y, z;
};

static void PrintMemoryUsage()
{
	std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

int main()
{

	PrintMemoryUsage();
	std::string string = "William";
	PrintMemoryUsage();
	Object* obj = new Object; //created the heap 
	PrintMemoryUsage();
	{
		std::unique_ptr<Object> obj2 = std::make_unique<Object>(); //unique ptr will still call overloaded new
																   //operator because new is in unique ptr code
	}
	PrintMemoryUsage();
}