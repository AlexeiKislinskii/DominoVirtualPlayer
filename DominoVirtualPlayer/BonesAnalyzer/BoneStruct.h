#pragma once
namespace BonesAnalyzer
{
	struct Bone
	{
		Bone(int left, int right) : Left(left), Right(right) {};

		int GetLeft() const { return this->Left; }
		int GetRight() const { return this->Right; }

	private:
		int Left, Right;
	};
}


