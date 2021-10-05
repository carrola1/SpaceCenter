#ifndef WAV_PLAYER_HPP
#define WAV_PLAYER_HPP

#include "main.h"
#include "stm32l0xx_hal.h"
#include "diskio.h"
#include "ff.h"

class WavPlayer {

  public:
    // Constructor
    WavPlayer(I2S_HandleTypeDef &hi2s);
    ~WavPlayer();

    FRESULT fr;     /* FatFs return code */

    void play_atomic(char wav_file[32]);
    void open_wav(char wav_file[32]);
    uint8_t play_dma(void);
    void close_wav(void);

    uint8_t wavOpen = 0;
    uint8_t audioPlaying = 0;

  private:
    I2S_HandleTypeDef &i2sHandle;
    uint8_t wav_buf[512];
    UINT bytes_read;

    FIL fil;
    uint16_t audio_buf_0[256];
    uint16_t audio_buf_1[256];
    uint16_t *audio_buf_ptr;
    uint16_t *audio_buf_ptr_start;
    
};

#endif
