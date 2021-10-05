#include "WavPlayer.hpp"

WavPlayer::WavPlayer(I2S_HandleTypeDef &hi2s) : i2sHandle(hi2s) {
}

WavPlayer::~WavPlayer() {
}

void WavPlayer::play_atomic(char wav_file[32]) {
    HAL_GPIO_WritePin(AUDIO_SD_N_L_GPIO_Port, AUDIO_SD_N_L_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(AUDIO_SD_N_R_GPIO_Port, AUDIO_SD_N_R_Pin, GPIO_PIN_SET);
    fr = f_open(&fil, wav_file, FA_READ);  // open file
    //f_lseek(&fil, 76);                      // move to data region of .wav
    audio_buf_ptr = audio_buf_0;        // point to buffer 0 first
    audio_buf_ptr_start = audio_buf_0;

    while(1) {
        f_read(&fil, &wav_buf[0], 512, &bytes_read);

        //////////// End of File ////////////
        if (bytes_read < 512) {
            f_close(&fil);
            HAL_GPIO_WritePin(AUDIO_SD_N_L_GPIO_Port, AUDIO_SD_N_L_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(AUDIO_SD_N_R_GPIO_Port, AUDIO_SD_N_R_Pin, GPIO_PIN_RESET);
            return;
        }
        //////////// End of File ////////////

        // convert raw bytes from wav file into 16-bit audio samples
        for (int ii=0; ii<511; ii+=2) {
            *audio_buf_ptr = ((uint16_t)wav_buf[ii+1] << 8) | (uint16_t)wav_buf[ii];
            if (*audio_buf_ptr > 32767) {
                *audio_buf_ptr = (*audio_buf_ptr >> 1) + 32768;
            } else {
                *audio_buf_ptr = *audio_buf_ptr >> 1;
            }
            audio_buf_ptr++;
        }

        while (i2sHandle.State != HAL_I2S_STATE_READY);    // Wait for I2S to be ready
        HAL_I2S_Transmit_DMA(&i2sHandle, audio_buf_ptr_start, 256);    // play buffer
        
        // ping pong buffer
        if (audio_buf_ptr_start == &audio_buf_0[0]) {
            audio_buf_ptr = &audio_buf_1[0];
            audio_buf_ptr_start = &audio_buf_1[0];
        } else {
            audio_buf_ptr = &audio_buf_0[0];
            audio_buf_ptr_start = &audio_buf_0[0];
        }
    }
    
}

void WavPlayer::open_wav(char wav_file[32]) {

  if (wavOpen) {
    close_wav();
  }   

  HAL_GPIO_WritePin(AUDIO_SD_N_L_GPIO_Port, AUDIO_SD_N_L_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(AUDIO_SD_N_R_GPIO_Port, AUDIO_SD_N_R_Pin, GPIO_PIN_SET);
  fr = f_open(&fil, wav_file, FA_READ);  // open file
  audio_buf_ptr = audio_buf_0;        // point to buffer 0 first
  audio_buf_ptr_start = audio_buf_0;
  wavOpen = 1;
}

uint8_t WavPlayer::play_dma(void) {
  f_read(&fil, &wav_buf[0], 512, &bytes_read);

  //////////// End of File ////////////
  if (bytes_read < 512) {
    audioPlaying = 0;
    f_close(&fil);
    HAL_GPIO_WritePin(AUDIO_SD_N_L_GPIO_Port, AUDIO_SD_N_L_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(AUDIO_SD_N_R_GPIO_Port, AUDIO_SD_N_R_Pin, GPIO_PIN_RESET);
    return 1;
  }

  // convert raw bytes from wav file into 16-bit audio samples
  for (int ii=0; ii<511; ii+=2) {
      *audio_buf_ptr = ((uint16_t)wav_buf[ii+1] << 8) | (uint16_t)wav_buf[ii];
      if (*audio_buf_ptr > 32767) {
          *audio_buf_ptr = (*audio_buf_ptr >> 1) + 32768;
      } else {
          *audio_buf_ptr = *audio_buf_ptr >> 1;
      }
      audio_buf_ptr++;
  }

  while (i2sHandle.State != HAL_I2S_STATE_READY);    // Wait for I2S to be ready
  audioPlaying = 1;
  HAL_I2S_Transmit_DMA(&i2sHandle, audio_buf_ptr_start, 256);    // play buffer
  
  // ping pong buffer
  if (audio_buf_ptr_start == &audio_buf_0[0]) {
      audio_buf_ptr = &audio_buf_1[0];
      audio_buf_ptr_start = &audio_buf_1[0];
  } else {
      audio_buf_ptr = &audio_buf_0[0];
      audio_buf_ptr_start = &audio_buf_0[0];
  }

  return 0;

}

void WavPlayer::close_wav(void) {
  f_close(&fil);
  HAL_GPIO_WritePin(AUDIO_SD_N_L_GPIO_Port, AUDIO_SD_N_L_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(AUDIO_SD_N_R_GPIO_Port, AUDIO_SD_N_R_Pin, GPIO_PIN_RESET);
  wavOpen = 0;
}

void HAL_I2S_TxCpltCallback(I2S_HandleTypeDef* hi2s) {
  return;
}
