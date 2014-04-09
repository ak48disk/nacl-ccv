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

namespace {
#include "cascade.h"
ccv_bbf_classifier_cascade_t* face_cascade = ccv_bbf_read_classifier_cascade();
} //namespace

namespace ccv_glue {

FaceDetector::FaceDetector() { }

pp::VarDictionary FaceDetector::DoFaceDetection(pp::VideoFrame& frame) {
    const void* data = static_cast<const void*>(frame.GetDataBuffer());
    uint32_t buffer_size = frame.GetDataBufferSize();
    pp::Size size;
    pp::VarDictionary retVal;
    pp::VarArray ppFaces;
    frame.GetSize(&size);
    
    int32_t width = size.width();
    int32_t height = size.height();
    ccv_dense_matrix_t* image = 0;
    ccv_read(data, &image, CCV_IO_BGRA_RAW | CCV_IO_GRAY, height, width,  buffer_size / height);
    //printf("%d %d %d\n",width,height,buffer_size);
    PP_DCHECK(image != 0);

    ccv_array_t* faces = ccv_bbf_detect_objects(image, &face_cascade, 1, ccv_bbf_default_params);

    int i;
    for(i = 0; i <faces->rnum; i++)
    {
        ccv_comp_t* face = (ccv_comp_t*)ccv_array_get(faces, i);
        pp::VarDictionary ppFace;
        ppFace.Set(pp::Var("x"), face->rect.x);
	    ppFace.Set(pp::Var("y"), face->rect.y);
	    ppFace.Set(pp::Var("width"), face->rect.width);
	    ppFace.Set(pp::Var("height"), face->rect.height);
        ppFaces.Set(i, ppFace);
    }    

    ccv_array_free(faces);
    ccv_matrix_free(image);

    retVal.Set("faces", ppFaces);    

    return retVal;
}


} //namespace
