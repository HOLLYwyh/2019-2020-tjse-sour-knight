#pragma once
#ifndef __SOUND_H__
#define __SOUND_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

extern bool doContinueGame;
extern bool soundCondition;
extern bool musicCondition;
extern float musicVolume;
extern float soundVolumn;
//void init();
void playMusic(const char* music, bool loop, int command);
void playMusic(const char* music, bool loop);
void playSound(const char* sound, int command);
void playSound(const char* sound);
void MusicVolumnIncrease();
void MusicVolumnDecrease();
void SoundVolumnIncrease();
void SoundVolumnDecrease();

#endif // __SOUND_H__

//#define __SOUND_H__