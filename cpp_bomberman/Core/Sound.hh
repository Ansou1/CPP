#ifndef SOUND_HH_
#define SOUND_HH_

#include <iostream>
#include "Exception.hpp"
#include "../libfmod/api/inc/fmod.hpp"
#include "../libfmod/api/inc/fmod_errors.h"
#include <map>

class	Sound
{
public:
  enum Music { INTRO, GAME, BOMB, KILL, VICTORY, BONUS, START, DEFEAT, DRAW };

private:
  FMOD::System	*system;
  FMOD::Sound	*sound[15];
  FMOD::Channel	*channel[3];

  std::map<Sound::Music, std::string>	_music;

  int					_level;

public:
  Sound();
  ~Sound();
  void				playMusic(Sound::Music e);
  void				stopMusic(Sound::Music e);
  void				checkError(FMOD_RESULT result) const;
  void				pauseChan(Sound::Music e);
  void				unpauseChan(Sound::Music e);
  void				setVolume(int vol);
};

#endif /* !SOUND_HH_ */
