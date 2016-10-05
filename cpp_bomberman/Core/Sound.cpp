//
// Sound.cpp for Bomby in /home/plourd_b/projets/bomby/cpp_bomberman/Core
//
// Made by Alexandre
// Login   <plourd_b@epitech.net>
//
// Started on  Tue Jun 10 16:35:54 2014 Alexandre
// Last update Sun Jun 15 15:55:15 2014 Boulot
//

#include "Sound.hh"

Sound::Sound()
{
  FMOD_RESULT	result;
  unsigned int	version;

  result = FMOD::System_Create(&system);
  checkError(result);
  result = system->getVersion(&version);
  checkError(result);
  result = system->init(32, FMOD_INIT_NORMAL, 0);
  checkError(result);
  result = system->createSound("./Core/Sound/Menu.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0, &sound[(int)Sound::INTRO]);
  checkError(result);
  result = system->createSound("./Core/Sound/musique_fond.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0, &sound[(int)Sound::GAME]);
  checkError(result);
  result = system->createSound("./Core/Sound/Kill.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &sound[(int)Sound::KILL]);
  checkError(result);
  result = system->createSound("./Core/Sound/VictorySound.wav", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &sound[(int)Sound::VICTORY]);
  checkError(result);
  result = system->createSound("./Core/Sound/Bonus.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &sound[(int)Sound::BONUS]);
  checkError(result);
  result = system->createSound("./Core/Sound/StartGame.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &sound[(int)Sound::START]);
  checkError(result);
  result = system->createSound("./Core/Sound/explosion.wav", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &sound[(int)Sound::BOMB]);
  checkError(result);
  result = system->createSound("./Core/Sound/DrawSound.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &sound[(int)Sound::DRAW]);
  checkError(result);
  result = system->createSound("./Core/Sound/DefeatSound2.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &sound[(int)Sound::DEFEAT]);
  checkError(result);

  _level = 50;
}

Sound::~Sound()
{
  FMOD_RESULT	result;
  int	i;

  i = 0;
  while (i < 15)
    {
      result = sound[i]->release();
      this->checkError(result);
      i++;
    }
  result = system->close();
  this->checkError(result);
  result = system->release();
  this->checkError(result);
}

void	Sound::playMusic(Sound::Music e)
{
  FMOD_RESULT	result;

  result = system->playSound(FMOD_CHANNEL_FREE, sound[(int)e], false, &channel[(int)e]);
  checkError(result);
  result = channel[(int)e]->setVolume((float)_level / 100.0);
  checkError(result);
  result = channel[(int)e]->setPaused(false);
  checkError(result);
}

void	Sound::stopMusic(Sound::Music e)
{
  FMOD_RESULT	result;

  result = system->playSound(FMOD_CHANNEL_FREE, sound[(int)e], true, &channel[(int)e]);
  checkError(result);
}

void	Sound::pauseChan(Sound::Music e)
{
  FMOD_RESULT	result;

  result = channel[(int)e]->setPaused(true);
  checkError(result);
}

void	Sound::setVolume(int vol)
{
  bool		isplaying;
  bool		paused;
  FMOD_RESULT	result;

  _level = vol;
  for (int i = (int)Sound::INTRO; i <= (int)Sound::DRAW; ++i)
    {
      result = channel[i]->isPlaying(&isplaying);
      checkError(result);
      if (isplaying)
	{
	  result = channel[i]->setVolume((float)_level / 100.0);
	  checkError(result);
	  result = channel[i]->getPaused(&paused);
	  checkError(result);
	  if (!paused)
	    {
	      result = channel[i]->setPaused(false);
	      checkError(result);
	    }
	}
    }

}

void	Sound::unpauseChan(Sound::Music e)
{
  FMOD_RESULT	result;

  result = channel[(int)e]->setPaused(false);
  checkError(result);
}

void	Sound::checkError(FMOD_RESULT result) const
{
  if (result != FMOD_OK && (result != FMOD_ERR_INVALID_HANDLE))
    {
      std::stringstream err;

      err << "FMOD error! " << result << " " << FMOD_ErrorString(result);
      throw my_exception((err.str()).c_str());
    }
}
