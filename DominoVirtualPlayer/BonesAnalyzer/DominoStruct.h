#pragma once
namespace BonesAnalyzer
{
	struct Domino
	{
		Domino(unsigned int left, unsigned int right)
		{
			this->Left = left;
			this->Right = right;
		};

		unsigned int GetLeft() const { return this->Left; }
		unsigned int GetRight() const { return this->Right; }

	private:
		unsigned int Left, Right;
	};
}

