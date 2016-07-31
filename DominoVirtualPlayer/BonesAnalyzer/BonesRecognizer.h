#pragma once
#include <vector>
#include "BoneStruct.h"

#include <opencv2/core/core.hpp>

namespace BonesAnalyzer
{
	class BonesRecognizer
	{
	public:
		BonesRecognizer();
		~BonesRecognizer();

		std::vector<Bone>* Recognize(cv::Mat input);

	};
}


