#include "CaptureEffect.h"

using namespace BonesAnalyzer;
using namespace Platform;

void CaptureEffect::Close(MediaEffectClosedReason reason)
{

}

void CaptureEffect::DiscardQueuedFrames()
{

}

void CaptureEffect::SetEncodingProperties(VideoEncodingProperties^ encodingProperties, IDirect3DDevice ^ device)
{

}

void CaptureEffect::SetProperties(IPropertySet ^ configuration)
{

}

void CaptureEffect::ProcessFrame(ProcessVideoFrameContext^ context)
{
	//convert from SoftwareBitmap to Mat
	cv::Mat cvFrame = this->Convert(context->InputFrame->SoftwareBitmap);

	int stop = 24;
}

cv::Mat CaptureEffect::Convert(SoftwareBitmap^ from)
{
	BitmapBuffer^ bmpBuffer = from->LockBuffer(BitmapBufferAccessMode::Read);

	ComPtr<IMemoryBufferByteAccess> bufferByteAccess;

	reinterpret_cast<IInspectable*>(bmpBuffer->CreateReference())->QueryInterface(IID_PPV_ARGS(&bufferByteAccess));

	unsigned char* pPixels = nullptr;
	unsigned int capacity = 0;
	bufferByteAccess->GetBuffer(&pPixels, &capacity);

	cv::Mat mat(from->PixelHeight, from->PixelWidth, CV_8UC4);
	memcpy(mat.data, pPixels, 4 * from->PixelHeight * from->PixelWidth);

	return mat;
}

SoftwareBitmap^ CaptureEffect::Convert(cv::Mat from)
{
	SoftwareBitmap^ sBitmap = ref new SoftwareBitmap(BitmapPixelFormat::Bgra8, from.cols, from.rows, BitmapAlphaMode::Ignore);
	BitmapBuffer^ bmpBuffer = sBitmap->LockBuffer(BitmapBufferAccessMode::ReadWrite);

	ComPtr<IBufferByteAccess> bufferByteAccess;
	ComPtr<IInspectable> insp((IInspectable*)bmpBuffer->CreateReference());
	insp.As(&bufferByteAccess);

	unsigned char* dstPixels = nullptr;
	bufferByteAccess->Buffer(&dstPixels);

	memcpy(dstPixels, from.data, from.step.buf[1] * from.cols*from.rows);

	return sBitmap;
}