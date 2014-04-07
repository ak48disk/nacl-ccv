namespace pp{
class VarDictionary;
class VideoFrame;
}
namespace ccv_glue {
    class FaceDetector {
    public:
        FaceDetector();
        pp::VarDictionary DoFaceDetection(pp::VideoFrame& frame);
    };
}
