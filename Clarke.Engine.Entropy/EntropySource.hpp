#pragma once
#include <random>

namespace clarke::engine::entropy
{
	class EntropySource
	{
		std::minstd_rand entropySource_;
	public:
		EntropySource(int seed) : entropySource_(seed) {}

		int getInrange(int from, int to);
	};
}
