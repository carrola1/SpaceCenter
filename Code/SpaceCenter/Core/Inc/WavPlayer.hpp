#ifndef WAV_PLAYER_HPP
#define WAV_PLAYER_HPP

#include "main.h"
#include "stm32l0xx_hal.h"
#include "diskio.h"
#include "ff.h"

#define CHUNK_SIZE 512

class WavPlayer {

  public:
    // Constructor
    WavPlayer(I2S_HandleTypeDef &hi2s);
    ~WavPlayer();

    FRESULT fr;     /* FatFs return code */

    void play_atomic(char wav_file[32]);
    void open_wav(char wav_file[32]);
    uint8_t play_chunk(void);
    void close_wav(void);

    uint8_t wavOpen = 0;
    uint8_t audioPlaying = 0;

  private:
    void ping_pong(void);
    void get_next_chunk(void);
    I2S_HandleTypeDef &i2sHandle;
    uint8_t wav_buf[CHUNK_SIZE];
    UINT bytes_read;

    FIL fil;
    uint16_t audio_buf_0[CHUNK_SIZE/2];
    uint16_t audio_buf_1[CHUNK_SIZE/2];
    uint16_t *audio_buf_ptr;
    uint16_t *audio_buf_ptr_start;
    
};

#endif
