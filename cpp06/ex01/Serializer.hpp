#pragma once

#include <cstdint>

typedef struct s_data
{
	int	x;
}				Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &serializer);
	Serializer	&operator=(const Serializer &rhs);
	~Serializer();
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};
