#include "ARToolkitRecipient.h"
#include "ImageAndCloud.h"
#include "RecordingFrame.h"
#include "VideoRecipient.h"


ARToolKitRecipient::ARToolKitRecipient(KinectFrameDesc &kfd, int imageNumber) : _imageNumber(imageNumber) {}

ARToolKitRecipient::~ARToolKitRecipient() {}

void ARToolKitRecipient::update(shared_ptr<RecordingFrame> rf)
{
	shared_ptr<ImageAndCloud> iac = rf->getImageAndCloud(_imageNumber);
	IplImage *colourImage = iac->getColorImage();

	fireUpdate(colourImage);
}

void ARToolKitRecipient::addVR(VideoRecipient *vr) {
	_vr.push_back(vr);
}

void ARToolKitRecipient::fireUpdate(IplImage *colorImage) {
	for (int i = 0; i < _vr.size(); i++) _vr[i]->update(colorImage);
}
