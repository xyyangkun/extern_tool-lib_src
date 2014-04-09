#include <ctype.h>
extern "C"{
#ifdef __cplusplus
 #define __STDC_CONSTANT_MACROS
 #ifdef _STDINT_H
  #undef _STDINT_H
 #endif
 # include <stdint.h>
#endif

#include "libavformat/avformat.h"
#include "libavdevice/avdevice.h"
#include "libswscale/swscale.h"
# include "libavfilter/avfilter.h"
# include "libavfilter/avfiltergraph.h"
}
int main()
{
	avcodec_register_all();
	avdevice_register_all();
	avfilter_register_all();
	av_register_all();
	
	
}
