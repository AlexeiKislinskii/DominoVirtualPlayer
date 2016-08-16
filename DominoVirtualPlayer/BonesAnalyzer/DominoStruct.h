#pragma once
namespace BonesAnalyzer
{
	ref struct Domino
	{
		Domino(unsigned int left, unsigned int right)
		{
			this->m_Left = left;
			this->m_Right = right;
		};


		property int Left
		{
			int get() { return this->m_Left; }
		}

		property int Right
		{
			int get() { return this->m_Right; }
		}

	private:
		unsigned int m_Left, m_Right;
	};
}

