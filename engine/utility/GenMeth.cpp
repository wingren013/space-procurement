float	GenMeth::random_float_in_range(float a, float b)
{
	std::random_device					r;
	std::mt19937						mersenne(r);
	std::uniform_real_distribution<>	random_range(a, b);
	
	return (random_range(mersenne));
}