#pragma once
#include <collection.h>
#include <ppltasks.h>
#include "MemoryBuffer.h"
#include "Robuffer.h"
#include "AI.h"

#include <opencv2/opencv.hpp>

using namespace Windows::Media::Effects;
using namespace Windows::Media::MediaProperties;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::DirectX::Direct3D11;
using namespace Windows::Graphics::Imaging;
using namespace Windows::Foundation::Collections;
using namespace Platform::Collections;
using namespace Windows::Foundation;
using namespace Microsoft::WRL;
using namespace Windows::Storage::Streams;

namespace BonesAnalyzer
{
	public ref class CaptureEffect sealed : IBasicVideoEffect
	{
	public:
		virtual void Close(MediaEffectClosedReason reason);
		virtual void DiscardQueuedFrames();
		virtual void SetEncodingProperties(VideoEncodingProperties^ encodingProperties, IDirect3DDevice^ device);
		virtual void SetProperties(IPropertySet^ configuration);
		virtual void ProcessFrame(ProcessVideoFrameContext^ context);

		property bool IsReadOnly { virtual bool get() { return true; } }
		property IVectorView<VideoEncodingProperties^>^ SupportedEncodingProperties
		{
			virtual IVectorView<VideoEncodingProperties^>^ get()
			{
				auto vec = ref new Vector<VideoEncodingProperties^>();

				auto encodingProperties = ref new VideoEncodingProperties();
				encodingProperties->Subtype = "ARGB32";

				vec->Append(encodingProperties);

				return vec->GetView();
			};
		}
		property MediaMemoryTypes SupportedMemoryTypes { virtual MediaMemoryTypes get() { return MediaMemoryTypes::Cpu; } }
		property bool TimeIndependent { virtual bool get() { return true; } }

	private:
		//http://stackoverflow.com/questions/34198259/winrt-c-win10-opencv-hsv-color-space-image-display-artifacts
		cv::Mat Convert(SoftwareBitmap^ from);
		SoftwareBitmap^ Convert(cv::Mat from);
	};
}
