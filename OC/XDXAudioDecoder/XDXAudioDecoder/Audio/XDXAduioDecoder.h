//
//  XDXAduioDecoder.h
//  XDXAudioUnitCapture
//
//  Created by 小东邪 on 2019/5/12.
//  Copyright © 2019 小东邪. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>

NS_ASSUME_NONNULL_BEGIN

@interface XDXAduioDecoder : NSObject
{
    @public
    AudioConverterRef           mAudioConverter;
    AudioStreamBasicDescription mDestinationFormat;
    AudioStreamBasicDescription mSourceFormat;
}

/**
 Init Audio Encoder
 @param sourceFormat source audio data format
 @param destFormatID destination audio data format
 @param isUseHardwareDecode Use hardware / software encode
 @return object.
 */
- (instancetype)initWithSourceFormat:(AudioStreamBasicDescription)sourceFormat
                        destFormatID:(AudioFormatID)destFormatID
                          sampleRate:(float)sampleRate
                 isUseHardwareDecode:(BOOL)isUseHardwareDecode;

/**
 Encode Audio Data
 @param sourceBuffer source audio data
 @param sourceBufferSize source audio data size
 @param completeHandler get audio data after encoding
 */
- (void)decodeAudioWithSourceBuffer:(void *)sourceBuffer
                   sourceBufferSize:(UInt32)sourceBufferSize
                    completeHandler:(void(^)(AudioBufferList *destBufferList, UInt32 outputPackets, AudioStreamPacketDescription *outputPacketDescriptions))completeHandler;


- (void)freeDecoder;

@end

NS_ASSUME_NONNULL_END
