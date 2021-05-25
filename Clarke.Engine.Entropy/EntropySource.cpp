#include "EntropySource.hpp"

int clarke::engine::entropy::EntropySource::getInrange(int from, int to)
{
	return from + (entropySource_() % (from - to));
}
