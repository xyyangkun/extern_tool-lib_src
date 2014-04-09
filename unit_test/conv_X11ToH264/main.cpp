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
#include "libavfilter/avfilter.h"
#include "libavfilter/avfiltergraph.h"
}
int main()
{
	avcodec_register_all();
	avdevice_register_all();
	avfilter_register_all();
	av_register_all();

	//whill open x11grab
	char *filename=":0.0";
	AVFormatContext *pFormatCtx = NULL;
	AVDictionary *options = NULL;
	AVInputFormat * p_in_fmt = NULL;

	p_in_fmt = av_find_input_format("x11grab");
	//av_dict_set(&options, "i", ":0.0", 0);
	av_dict_set(&options, "framerate", "25", 0);
	av_dict_set(&options, "video_size", "640x480", 0);
	if (avformat_open_input(&pFormatCtx, filename, p_in_fmt, &options) < 0)
	{
		printf("cannot open input file!\n");
		abort();
	}
	av_dict_free(&options);
	printf("open x11grab ok\n");

	//Retrieve stream infomation
	if(avformat_find_stream_info(pFormatCtx, NULL) < 0)
	{
		printf("could't find stream infomation\n");
		return -1;
	}	
	// Dump information about file onto standard error
	av_dump_format(pFormatCtx, 0, "test", 0);	

	// Find the first video stream	
	int i, videoStream;
	videoStream = -1;
    	for (i = 0; i < pFormatCtx->nb_streams; i++)
    	if (pFormatCtx->streams[i]->codec->codec_type 
                                == AVMEDIA_TYPE_VIDEO)
   	{
        	videoStream = i;
        	break;
    	}
    	if (videoStream == -1)
        	return -1; // Didn't find a video stream	

   	// Get a pointer to the codec context for the video stream
    	AVCodecContext *pCodecCtx;
	AVCodec *pCodec;
    	AVFrame *pFrame;
	pCodecCtx = pFormatCtx->streams[videoStream]->codec;

    	// Find the decoder for the video stream
    	pCodec = avcodec_find_decoder(pCodecCtx->codec_id);
    	if (pCodec == NULL) {
        	fprintf(stderr, "Unsupported codec!\n");
        	return -1; // Codec not found
    	}
    	// Open codec
    	if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0)
        	return -1; // Could not open codec
	printf("over\n");
}
