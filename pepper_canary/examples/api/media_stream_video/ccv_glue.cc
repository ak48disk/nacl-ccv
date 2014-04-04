extern "C" {
#include "ccv/ccv.h"
}
#include "ppapi/c/pp_errors.h"
#include "ppapi/cpp/completion_callback.h"
#include "ppapi/cpp/module.h"
#include "ppapi/cpp/media_stream_video_track.h"
#include "ppapi/cpp/var.h"
#include "ppapi/cpp/video_frame.h"
#include "ccv_glue.h"

namespace ccv_glue {

CCVGule::CCVGule() { }

pp::VarDictionary DoFaceDetection(pp::VideoFrame& frame) {
    const void* data = static_cast<const void*>(frame.GetDataBuffer());
    uint32_t buffer_size = frame.GetDataBufferSize();
    pp::Size size;
    pp::VarDictionary retVal;
    PP_DCHECK(frame.GetSize(&size));
    
    int32_t width = size.width();
    int32_t height = size.height();
    
    
    return retVal;
}


} //namespace
