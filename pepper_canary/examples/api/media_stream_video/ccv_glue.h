namespace pp{
class VarDictionary;
class VideoFrame;
}
namespace ccv_glue {
    class CCVGule {
    public:
        CCVGule();
        pp::VarDictionary DoFaceDetection(const pp::VideoFrame& frame);
    };
}