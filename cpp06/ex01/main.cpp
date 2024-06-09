#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		*ptr;
	uintptr_t	raw_ptr;

	ptr = new Data;
	std::cout << "Original pointer to Data struct: " << ptr << std::endl;
	raw_ptr = Serializer::serialize(ptr);
	std::cout << "Serialized pointer: " << raw_ptr << std::endl;
	ptr = Serializer::deserialize(raw_ptr);
	std::cout << "Deserialized pointer to Data struct: " << ptr << std::endl;
	delete ptr;

	return 0;
}
