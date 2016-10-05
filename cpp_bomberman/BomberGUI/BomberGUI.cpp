//
// BomberGUI.cpp for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Fri May  9 10:39:40 2014 lerman_v
// Last update Sun Jun 15 16:27:55 2014 lerman_v
//

#include "BomberGUI.hh"

// -----------------------------------------------------------------------------
// - Init                                                                      -
// -----------------------------------------------------------------------------

BomberGUI::BomberGUI()
{
  _playerBind[0][SDLK_UP] = Data::GO_UP;
  _playerBind[0][SDLK_DOWN] = Data::GO_DOWN;
  _playerBind[0][SDLK_LEFT] = Data::GO_LEFT;
  _playerBind[0][SDLK_RIGHT] = Data::GO_RIGHT;
  _playerBind[0][SDLK_SPACE] = Data::DROP_BOMB;

  _playerBind[1][SDLK_z] = Data::GO_UP;
  _playerBind[1][SDLK_s] = Data::GO_DOWN;
  _playerBind[1][SDLK_q] = Data::GO_LEFT;
  _playerBind[1][SDLK_d] = Data::GO_RIGHT;
  _playerBind[1][SDLK_r] = Data::DROP_BOMB;

  _inputPut.push_back('a');
  _inputPut.push_back('b');
  _inputPut.push_back('c');
  _inputPut.push_back('d');
  _inputPut.push_back('e');
  _inputPut.push_back('f');
  _inputPut.push_back('g');
  _inputPut.push_back('h');
  _inputPut.push_back('i');
  _inputPut.push_back('j');
  _inputPut.push_back('k');
  _inputPut.push_back('l');
  _inputPut.push_back('m');
  _inputPut.push_back('n');
  _inputPut.push_back('o');
  _inputPut.push_back('p');
  _inputPut.push_back('q');
  _inputPut.push_back('r');
  _inputPut.push_back('s');
  _inputPut.push_back('t');
  _inputPut.push_back('u');
  _inputPut.push_back('v');
  _inputPut.push_back('w');
  _inputPut.push_back('x');
  _inputPut.push_back('y');
  _inputPut.push_back('z');
  _inputPut.push_back('A');
  _inputPut.push_back('B');
  _inputPut.push_back('C');
  _inputPut.push_back('D');
  _inputPut.push_back('E');
  _inputPut.push_back('F');
  _inputPut.push_back('G');
  _inputPut.push_back('H');
  _inputPut.push_back('I');
  _inputPut.push_back('J');
  _inputPut.push_back('K');
  _inputPut.push_back('L');
  _inputPut.push_back('M');
  _inputPut.push_back('N');
  _inputPut.push_back('O');
  _inputPut.push_back('P');
  _inputPut.push_back('Q');
  _inputPut.push_back('R');
  _inputPut.push_back('S');
  _inputPut.push_back('T');
  _inputPut.push_back('U');
  _inputPut.push_back('V');
  _inputPut.push_back('W');
  _inputPut.push_back('X');
  _inputPut.push_back('Y');
  _inputPut.push_back('Z');
  
  _mapSelect.push_back("Random");
  _mapSelect.push_back("Classic");

  _soundLevel = 50;
  _isMute = true;

  _GameManager = new GameManager(&_input, &_clock, &_shader, _playerBind, _playerBind + 1);
}

BomberGUI::~BomberGUI()
{

}

bool		BomberGUI::createWindow(int width, int height)
{

  if (!_context.start(width, height, "Bomberman"))
    throw my_exception("BomberGUI: cannot create window");

  glEnable(GL_DEPTH_TEST);
  glAlphaFunc(GL_GREATER, 0.1f);
  glEnable(GL_ALPHA_TEST);

  if (!_shader.load("./BomberGUI/Shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./BomberGUI/Shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    throw my_exception("BomberGUI: cannot init shader");
      _ratio = (float)width / (float)height;
  if (!setCamera(glm::vec3(1, 30, 0)))
    return false;
  initObjects();
  return (true);
}

bool		BomberGUI::setCamera(glm::vec3 const& origin)
{
  glm::mat4 projection;
  glm::mat4 transformation;

  
  projection = glm::perspective(FOV, _ratio, 0.1f,
				(float) (2.0 * sqrt(pow(origin.x, 2.0) + pow(origin.y, 2.0) + pow(origin.z, 2.0)) + 3.0));
  transformation = glm::lookAt(origin , glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);

  _camera = origin;
  return true;
}

bool		BomberGUI::initObjects()
{
  _objects[Data::EMPTY] = new Cube("./BomberGUI/Textures/Ground.tga");
  _objects[Data::EMPTY]->translate(glm::vec3(-0.5f, -1.0f, -0.5f));
  _objects[Data::CRATE] = new Cube("./BomberGUI/Textures/Box.tga");
  _objects[Data::WALL] = new Cube("./BomberGUI/Textures/Wall.tga");
  _objects[Data::BOOM] = new Cube("./BomberGUI/Textures/Boum.tga");
  _objects[Data::BOOM2] = new Cube("./BomberGUI/Textures/Boum.tga");
  _objects[Data::BONUS] = new Bonus("./BomberGUI/Textures/Bonus.tga");
  _objects[Data::OUT] = new Cube("./BomberGUI/Textures/IceCube.tga");
  return true;
}





// -----------------------------------------------------------------------------
// - Intro                                                                     -
// -----------------------------------------------------------------------------

void		BomberGUI::intro()
{
  float				timer = 12.0;
  float				alpha = PI / 2.0 * -0.1;
  Background			bg = Background("./BomberGUI/Textures/Background.tga",
  						glm::vec3(0, 0, -20),
  						FOV, _ratio);

  setCamera(glm::vec3(0, 0.0, 20.0));

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  bg.draw(_shader, _clock);
  _context.flush();

  _GameManager->initIntro();
  _GameManager->getSound()->pauseChan(Sound::INTRO);
  _GameManager->getSound()->unpauseChan(Sound::GAME);

  while (timer > 0.0 && update() && !_input.getKey(SDLK_f))
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      _shader.bind();

      _GameManager->updateCharacters();
      _GameManager->updateItems();

      drawMap(*(_GameManager->getMap()));

      bg.draw(_shader, _clock);

      _context.flush();

      timer -= _clock.getElapsed();
      if (timer > 2.0)
	{
	  setCamera(glm::vec3(0.0,
			      _camera.y * cos(alpha * _clock.getElapsed())
			      - _camera.z * sin(alpha * _clock.getElapsed()),
			      _camera.y * sin(alpha * _clock.getElapsed())
			      + _camera.z * cos(alpha * _clock.getElapsed())
			      ));
	  bg.resetPos(glm::vec3(-_camera.x, -_camera.y, -_camera.z), FOV, _ratio);
	}
    }

  _GameManager->reset();
}





// -----------------------------------------------------------------------------
// - Main Menu                                                                 -
// -----------------------------------------------------------------------------

void		BomberGUI::menu()
{
  std::vector<BlockMenu *>		item;
  std::vector<void (BomberGUI::*)()>	func;

  std::vector<AObject *>		toDraw;
  int					selected = 0;

  bool					activeUp = true, activeDown = true, activeReturn = true;

  setCamera(glm::vec3(0, 0, -6));

  Background	bg = Background("./BomberGUI/Textures/MenuPrincipal.tga",
				glm::vec3(-_camera.x, -_camera.y, -_camera.z),
				FOV, _ratio, true);

  item.push_back(new BlockMenu("./BomberGUI/Textures/play.tga"));
  func.push_back(&BomberGUI::MenuPlay);
  item[0]->translate(glm::vec3(0.0f, 2.25f, 0.0f));
  item.push_back(new BlockMenu("./BomberGUI/Textures/settings.tga"));
  func.push_back(&BomberGUI::MenuSetting);
  item[1]->translate(glm::vec3(0.0f, 0.75f, 0.0f));
  item.push_back(new BlockMenu("./BomberGUI/Textures/credits.tga"));
  func.push_back(&BomberGUI::Credit);
  item[2]->translate(glm::vec3(0.0f, -0.75f, 0.0f));
  item.push_back(new BlockMenu("./BomberGUI/Textures/exit.tga"));
  item[3]->translate(glm::vec3(0.0f, -2.25f, 0.0f));
  item[selected]->setAnime(BlockMenu::SELECT);
  _GameManager->getSound()->pauseChan(Sound::GAME);
  _GameManager->getSound()->unpauseChan(Sound::INTRO);
  for (std::vector<BlockMenu *>::iterator it = item.begin() ; it != item.end(); ++it)
    toDraw.push_back(*it);
  toDraw.push_back(&bg);
  while (update())
    {
      // Up
      if (_input.getKey(SDLK_UP))
  	  {
  	    if (activeUp)
  	    {
  	      activeUp = false;
  	      item[selected]->setAnime(BlockMenu::UNSELECT);
  	      selected = --selected < 0 ? item.size() - 1: selected;
  	      item[selected]->setAnime(BlockMenu::SELECT);
  	    }
  	}
      else
  	activeUp = true;

      // Down
      if (_input.getKey(SDLK_DOWN))
  	{
  	  if (activeDown)
  	    {
  	      activeDown = false;
  	      item[selected]->setAnime(BlockMenu::UNSELECT);
  	      selected = (selected + 1) % item.size();
  	      item[selected]->setAnime(BlockMenu::SELECT);
  	    }
  	}
      else
  	activeDown = true;

      // Select
      if (_input.getKey(SDLK_RETURN))
  	{
  	  if (activeReturn)
  	    {
	      activeReturn = false;
	      if (selected == (int)item.size() - 1)
		break;
	      ((*this).*func[selected])();
	      setCamera(glm::vec3(0, 0, -6));
	    }
  	}
      else
	activeReturn = true;

      // Draw
      bg.resetPos(glm::vec3(-_camera.x, -_camera.y, -_camera.z), FOV, _ratio);
      drawMenu(toDraw);
    }

  // Erase
  for (std::vector<BlockMenu *>::iterator it = item.begin() ; it != item.end(); ++it)
    delete(*it);
}





// -----------------------------------------------------------------------------
// - Sub Menu                                                                  -
// -----------------------------------------------------------------------------

void		BomberGUI::MenuPlay()
{
  std::vector<AObject *>		toDraw;

  int					menuElem = 0;
  int					item[5] = {1, 1, 0, 0, 5};
  std::stringstream			ss;

  bool					libNull = false, activeUp = true, activeDown = true,
					activeLeft = true, activeRight = true;
  bool					itemHasChange = true;

  AObject				*arrow;

  ScanDir				back("./backup", ".game");

  ss << item[0];
  toDraw.push_back(new TextGUI(ss.str(), "./BomberGUI/Textures/Font.tga",
  			       _camera, FOV / 2.0, _ratio,
  			       0.71, 0.1625, 0.15, 3));
  ss.str("");
  ss << item[1];
  toDraw.push_back(new TextGUI(ss.str(), "./BomberGUI/Textures/Font.tga",
  			       _camera, FOV / 2.0, _ratio,
  			       0.71, 0.300, 0.15, 3));
  toDraw.push_back(new TextGUI(_mapSelect[item[2]], "./BomberGUI/Textures/Font.tga",
  			       _camera, FOV / 2.0, _ratio,
  			       0.71, 0.445, 0.15, 3));
  toDraw.push_back(new TextGUI("---", "./BomberGUI/Textures/Font.tga",
  			       _camera, FOV / 2.0, _ratio,
  			       0.71, 0.590, 0.15, 3));
  ss.str("");
  ss << item[4];
  toDraw.push_back(new TextGUI(ss.str(), "./BomberGUI/Textures/Font.tga",
  			       _camera, FOV / 2.0, _ratio,
  			       0.71, 0.735, 0.15, 3));
  toDraw.push_back(new Background("./BomberGUI/Textures/MenuPlay.tga",
				  glm::vec3(-_camera.x, -_camera.y, -_camera.z),
				  FOV, _ratio, true));
  toDraw.push_back(arrow = new Arrow("./BomberGUI/Textures/White.tga"));
  arrow->translate(glm::vec3(-2, 2.35, 0));

  while (update())
    {
      // Return
      if (_input.getKey(SDLK_RETURN))
	{
	  if (libNull)
	    try // Try Init Game
	      {
		if (item[3] == 0)
		  {
		    _GameManager->initPlayers(item[0]);
		    _GameManager->initAI(item[1]);
		    _GameManager->initMap(item[4], item[4], item[2]);
		  }
		else
		  _GameManager->loadBackup(back.getFile(item[3] - 1).substr(0, back.getFile(item[3] - 1).rfind(".game")));
		break;
	      }
	    catch (my_exception const &e)
	      {
		std::cerr << e.what() << std::endl;
		_GameManager->reset(false);
		if (toDraw.size() == 7)
		  toDraw.push_back(new TextGUI(e.what(), "./BomberGUI/Textures/Font.tga",
					       _camera, FOV / 2.0, _ratio,
					       0.15, 0.825, 0.15, 3));
		else
		  {
		    delete (toDraw[7]);
		    toDraw[7] = new TextGUI(e.what(), "./BomberGUI/Textures/Font.tga",
					    _camera, FOV / 2.0, _ratio,
					    0.15, 0.825, 0.15, 3);
		  }
		libNull = false;
	      }
	}
      else
	libNull = true;

      // Up
      if (_input.getKey(SDLK_UP))
	{
	  if (activeUp && menuElem > 0)
  	    {
	      menuElem--;
	      arrow->translate(glm::vec3(0, 1, 0));
	      activeUp = false;
  	    }
  	}
      else
  	activeUp = true;

      // Down
      if (_input.getKey(SDLK_DOWN))
  	{
  	  if (activeDown && menuElem < 4)
  	    {
	      menuElem++;
	      arrow->translate(glm::vec3(0, -1, 0));
	      activeDown = false;
  	    }
  	}
      else
  	activeDown = true;

      // Left
      if (_input.getKey(SDLK_LEFT))
      	{
      	  if (activeLeft)
      	    {
      	      item[menuElem]--;
      	      activeLeft = itemHasChange = false;
      	    }
      	}
      else
      	activeLeft = true;

      // Right
      if (_input.getKey(SDLK_RIGHT))
      	{
      	  if (activeRight)
      	    {
      	      item[menuElem]++;
      	      activeRight = itemHasChange = false;
      	    }
      	}
      else
      	activeRight = true;

      if (!itemHasChange)
      	{
      	  item[0] = item[0] == 0 ? 2 : item[0] == 3 ? 1 : item[0];
	  item[1] = item[1] < 0 ? 0 : item[1] > MAXIA ? MAXIA : item[1];
	  item[2] = item[2] < 0 ? _mapSelect.size() - 1 : item[2] > (int)_mapSelect.size() - 1 ? 0 : item[2];
	  item[3] = item[3] < 0 ? 0 : item[3] > (int)back.getNbFiles() ? back.getNbFiles() : item[3];
	  item[4] = item[4] < MINMAP ? MINMAP : item[4] > MAXMAP ? MAXMAP : item[4];

	  ss.str("");

	  if (menuElem == 2)
	    ss << _mapSelect[item[menuElem]];
	  else if (menuElem == 3)
	    ss << (item[menuElem] == 0 ? "---" : back.getFile(item[menuElem] - 1));
	  else
	    ss << item[menuElem];

	  delete (toDraw[menuElem]);
	  toDraw[menuElem] = new TextGUI(ss.str(), "./BomberGUI/Textures/Font.tga",
					 _camera, FOV / 2.0, _ratio,
					 0.71, 0.1625 + (0.145 * menuElem), 0.15, 3);
	  itemHasChange = true;
	}

      // Rotate Arrow
      arrow->rotate(glm::vec3(1,0,0), _clock.getElapsed() * 100.0f);
      // Draw
      drawMenu(toDraw);
    }

  // Go Game
  setCamera(glm::vec3(0,
		      _GameManager->getMap()->getWidth(),
		      _GameManager->getMap()->getLength() / 2.0f)
	    );

  runGame();

  _GameManager->getSound()->pauseChan(Sound::GAME);
  _GameManager->getSound()->unpauseChan(Sound::INTRO);

  for (std::vector<AObject *>::iterator it = toDraw.begin() ; it != toDraw.end(); ++it)
    delete(*it);
}

bool		BomberGUI::MenuPause()
{
  std::vector<AObject *>		toDraw;
  AObject				*arrow;

  std::stringstream			ss;
  std::map<char, bool>			active;

  int					menuElem = 0;
  bool					ret = false;
  bool					libNull = false, activeUp = true, activeDown = true;


  setCamera(glm::vec3(0, 0, -6));
  toDraw.push_back(new Background("./BomberGUI/Textures/MenuPause.tga",
				  glm::vec3(-_camera.x, -_camera.y, -_camera.z),
				  FOV, _ratio, true));
  toDraw.push_back(arrow = new Arrow("./BomberGUI/Textures/White.tga"));
  toDraw.push_back(new TextGUI("", "./BomberGUI/Textures/Font.tga",
  			       _camera, FOV / 2.0, _ratio,
  			       0.25, 0.735, 0.15, 3));
  arrow->translate(glm::vec3(1.7, 2.35, 0));

  while (update())
    {
      // Return
      if (_input.getKey(SDLK_RETURN))
	{
	  if (libNull)
	    {
	      libNull = false;
	      ret = !menuElem;

	      if (menuElem == 1)
		while (update())
		  {
		    for (std::vector<char>::iterator it = _inputPut.begin(); it != _inputPut.end();++it)
		      if (_input.getKey(*it))
			{
			  if (active[(*it)])
			    {
			      active[(*it)] = false;
			      ss << (*it);
			      delete (*(toDraw.rbegin()));
			      *(toDraw.rbegin()) = new TextGUI(ss.str(),"./BomberGUI/Textures/Font.tga",
							       _camera, FOV / 2.0, _ratio,
							       0.40, 0.735, 0.15, 3);
			    }
			}
		      else
			active[(*it)] = true;

		    if (_input.getKey(SDLK_RETURN))
		      {
			if (libNull)
			  {
			    libNull = false;
			    _GameManager->backup(ss.str());
			    break;
			  }
		      }
		    else
		      libNull = true;

		    if (_input.getKey(SDLK_ESCAPE))
		      {
			ss.str("");
			delete (*(toDraw.rbegin()));
			*(toDraw.rbegin()) = new TextGUI(ss.str(),"./BomberGUI/Textures/Font.tga",
							 _camera, FOV / 2.0, _ratio,
							 0.71, 0.735, 0.15, 3);
			break;
		      }
		    // Rotate Arrow
		    arrow->rotate(glm::vec3(1,0,0), _clock.getElapsed() * 100.0f);
		    // Draw
		    drawMenu(toDraw);
		  }
	      if ((menuElem == 1 && libNull) || (menuElem != 1 && !libNull))
		break;
	    }
	}
      else
	libNull = true;

      // Up
      if (_input.getKey(SDLK_UP))
	{
	  if (activeUp && menuElem > 0)
  	    {
	      menuElem--;
	      arrow->translate(glm::vec3(0, 1, 0));
	      activeUp = false;
  	    }
  	}
      else
  	activeUp = true;

      // Down
      if (_input.getKey(SDLK_DOWN))
  	{
  	  if (activeDown && menuElem < 2)
  	    {
	      menuElem++;
	      arrow->translate(glm::vec3(0, -1, 0));
	      activeDown = false;
  	    }
  	}
      else
  	activeDown = true;

      // Rotate Arrow
      arrow->rotate(glm::vec3(1,0,0), _clock.getElapsed() * 100.0f);
      // Draw
      drawMenu(toDraw);
    }

  setCamera(glm::vec3(0,_GameManager->getMap()->getWidth(),_GameManager->getMap()->getLength() / 2.0f));

  for (std::vector<AObject *>::iterator it = toDraw.begin() ; it != toDraw.end(); ++it)
    delete(*it);
  return ret;
}

void		BomberGUI::MenuSetting()
{
  std::vector<AObject *>		toDraw;

  int					menuElem = 0;
  int					item[2] = {_soundLevel, (int)_isMute};
  std::stringstream			ss;

  bool					libNull = false, activeUp = true, activeDown = true,
					activeLeft = true, activeRight = true;
  bool					itemHasChange = true;

  AObject				*arrow;

  ss << item[0];
  toDraw.push_back(new TextGUI(ss.str(), "./BomberGUI/Textures/Font.tga",
  			       _camera, FOV / 2.0, _ratio,
  			       0.71, 0.1625, 0.15, 3));
  ss.str("");
  ss << (item[1] == 0 ? "OFF" : "ON");
  toDraw.push_back(new TextGUI(ss.str(), "./BomberGUI/Textures/Font.tga",
  			       _camera, FOV / 2.0, _ratio,
  			       0.71, 0.300, 0.15, 3));

  toDraw.push_back(new Background("./BomberGUI/Textures/MenuSetting.tga",
				  glm::vec3(-_camera.x, -_camera.y, -_camera.z),
				  FOV, _ratio, true));
  toDraw.push_back(arrow = new Arrow("./BomberGUI/Textures/White.tga"));
  arrow->translate(glm::vec3(-2, 2.35, 0));

  while (update())
    {
      // Return
      if (_input.getKey(SDLK_RETURN))
	{
	  if (libNull)
	    {
	      _soundLevel = item[0];
	      _isMute = (bool)item[1];
	      break;
	    }
	}
      else
	libNull = true;

      // Up
      if (_input.getKey(SDLK_UP))
	{
	  if (activeUp && menuElem > 0)
  	    {
	      menuElem--;
	      arrow->translate(glm::vec3(0, 1, 0));
	      activeUp = false;
  	    }
  	}
      else
  	activeUp = true;

      // Down
      if (_input.getKey(SDLK_DOWN))
  	{
  	  if (activeDown && menuElem < 1)
  	    {
	      menuElem++;
	      arrow->translate(glm::vec3(0, -1, 0));
	      activeDown = false;
  	    }
  	}
      else
  	activeDown = true;

      // Left
      if (_input.getKey(SDLK_LEFT))
      	{
      	  if (activeLeft)
      	    {
      	      item[menuElem]--;
      	      activeLeft = itemHasChange = false;
      	    }
      	}
      else
      	activeLeft = true;

      // Right
      if (_input.getKey(SDLK_RIGHT))
      	{
      	  if (activeRight)
      	    {
      	      item[menuElem]++;
      	      activeRight = itemHasChange = false;
      	    }
      	}
      else
      	activeRight = true;

      if (!itemHasChange)
      	{
      	  item[0] = item[0] < 0 ? 0 : item[0] > 100 ? 100 : item[0];
	  item[1] = item[1] == -1 ? 1 : item[1] == 2 ? 0 : item[1];

	  ss.str("");

	  if (menuElem == 1)
	    ss << (item[menuElem] == 0 ? "OFF" : "ON");
	  else
	      ss << item[menuElem];

	    _GameManager->getSound()->setVolume(item[1] * item[0]);

	  delete (toDraw[menuElem]);
	  toDraw[menuElem] = new TextGUI(ss.str(), "./BomberGUI/Textures/Font.tga",
					 _camera, FOV / 2.0, _ratio,
					 0.71, 0.1625 + (0.145 * menuElem), 0.15, 3);
	  itemHasChange = true;
	}

      // Rotate Arrow
      arrow->rotate(glm::vec3(1,0,0), _clock.getElapsed() * 100.0f);
      // Draw
      drawMenu(toDraw);
    }

  for (std::vector<AObject *>::iterator it = toDraw.begin() ; it != toDraw.end(); ++it)
    delete(*it);
}

void		BomberGUI::Credit()
{
  std::vector<AObject *>		toDraw;

  toDraw.push_back(new Background("./BomberGUI/Textures/CreditBg.tga",
				  glm::vec3(-_camera.x, -_camera.y, -_camera.z),
				  FOV, _ratio));
  while (!_input.getKey(SDLK_q))
    {
      drawMenu(toDraw);
      update();
    }
}





// -----------------------------------------------------------------------------
// - Draw                                                                      -
// -----------------------------------------------------------------------------

void		BomberGUI::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  _context.flush();
}

void		BomberGUI::drawMenu(std::vector<AObject *> const &items)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();

  for (std::vector<AObject *>::const_iterator it = items.begin() ; it != items.end(); ++it)
    (*it)->draw(_shader, _clock);

  _context.flush();
}

void		BomberGUI::drawMap(Map const &map)
{
  size_t	width, height;

  width = map.getWidth();
  height = map.getLength();

  for (std::map<Data::e_case, AObject *>::iterator it = _objects.begin(); it != _objects.end(); ++it)
    it->second->updateAnime(_clock);

  for (size_t x = 0; x < width; x++)
    for (size_t y = 0; y < height; y++)
      if (map.getCase(x, y) == Data::WALL
  	  || map.getCase(x, y) == Data::CRATE
  	  || map.getCase(x, y) == Data::BOOM
	  || map.getCase(x, y) == Data::BOOM2
	  || map.getCase(x, y) == Data::BONUS)
  	{
	  _objects[map.getCase(x, y)]
	    ->translate(glm::vec3(x - (width / 2.0), 0, y - (height / 2.0)));
	  _objects[map.getCase(x, y)]->draw(_shader, _clock);
	  _objects[map.getCase(x, y)]
	    ->translate(glm::vec3(-(x - (width / 2.0)), 0, -(y - (height / 2.0))));
  	}
  _objects[Data::EMPTY]->scale(glm::vec3(width += 2, 1, height += 2));
  _objects[Data::EMPTY]->draw(_shader, _clock);
  _objects[Data::EMPTY]->scale(glm::vec3(1.0 / (float)width, 1, 1.0 / (float)height));
}





// -----------------------------------------------------------------------------
// - Update                                                                    -
// -----------------------------------------------------------------------------

bool		BomberGUI::update()
{
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  if (_input.getInput(SDL_QUIT))
    throw my_exception("BomberGUI: Exit GUI");
  return true;
}


// -----------------------------------------------------------------------------
// - Game Loop                                                                 -
// -----------------------------------------------------------------------------

void	BomberGUI::runGame()
{
  int				winer;
  std::vector<AObject *>	items;

  std::vector<int>		score;
  std::vector<AObject *>	scoreGUI;

  AObject			*info;
  bool				moveBonus = false;

  std::stringstream		ss;
  float				ending;
  Background			bg = Background("./BomberGUI/Textures/Background.tga",
						glm::vec3(-_camera.x, -_camera.y, -_camera.z),
						FOV, _ratio);

  _GameManager->getSound()->pauseChan(Sound::INTRO);
  _GameManager->getSound()->unpauseChan(Sound::GAME);

  // Init Score
  winer = 0;
  for (std::map<int, int>::const_iterator it = _GameManager->getScore().begin();
       it != _GameManager->getScore().end(); ++it)
    {
      ss.str("");
      ss << "Joueur " << it->first + 1 << " - " << it->second;
      scoreGUI.push_back(new TextGUI(ss.str(),"./BomberGUI/Textures/Font.tga",
				     _camera, FOV / 2.0, _ratio,
				     0.1, 0.025 + 0.025 * winer, 0.075, 3, true));
      score.push_back(it->second);
      winer++;
    }

  // Game loop
  while (_GameManager->gameOver() && update())
    {
      if (_input.getKey(SDLK_ESCAPE) && !MenuPause())
	return _GameManager->reset();

      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      _shader.bind();

      _GameManager->updateCharacters();
      _GameManager->updateItems();

      drawMap(*(_GameManager->getMap()));

      // {Draw,Update}\ Score
      winer = 0;
      for (std::map<int, int>::const_iterator it = _GameManager->getScore().begin();
      	   it != _GameManager->getScore().end(); ++it)
      	{
	  if (score[winer] != it->second)
	    {
	      ss.str("");
	      ss << "Joueur " << it->first + 1 << " - " << it->second;
	      delete (scoreGUI[winer]);
	      scoreGUI[winer] = new TextGUI(ss.str(),"./BomberGUI/Textures/Font.tga",
					    _camera, FOV / 2.0, _ratio,
					    0.1, 0.025 + 0.025 * winer, 0.075, 3, true);
	      score[winer] = it->second;
	    }
	  scoreGUI[winer]->draw(_shader, _clock);
	  winer++;
      	}

      // {Draw,Update}\ Bonus
      // - Check Date / Delete out of date elem
      moveBonus = false;
      if (items.size() && dynamic_cast<TextGUI *>(*(items.begin()))->outOfDate())
	{
	  delete (*(items.begin()));
	  items.erase(items.begin());
	  moveBonus = true;
	}
      // - Draw / Move elem
      winer = 1;
      for (std::vector<AObject *>::iterator it = items.begin() ; it != items.end(); ++it)
	{
	  (*it)->updateAnime(_clock);
	  if (moveBonus)
	    {
	      info = *it;
	      *it = new TextGUI(dynamic_cast<TextGUI *>(info)->getStr(),"./BomberGUI/Textures/Font.tga",
				_camera, FOV / 2.0, _ratio,
				0.1, 1.0 - 0.025 * winer, 0.075, 3,
				true, dynamic_cast<TextGUI *>(info)->getPeriod());
	      delete (info);
	    }
	  (*it)->draw(_shader, _clock);
	  winer++;
	}
      // - Draw / add New item
      if (_GameManager->getMessage() != "")
	{
	  items.push_back(new TextGUI(_GameManager->getMessage(),"./BomberGUI/Textures/Font.tga",
				      _camera, FOV / 2.0, _ratio,
				      0.1, 1.0 - 0.025 * winer, 0.075, 3,
				      true, 5.0));
	  (*(items.rbegin()))->draw(_shader, _clock);
	}

      // Draw BG + Display all
      bg.draw(_shader, _clock);
      _context.flush();
    }

  // End Game Put To other Function
  setCamera(glm::vec3(0, 0, -6));
  ss.str("");

  if ((winer = _GameManager->whoIsWin()) == -2) // Draw
      items.push_back(new Background("./BomberGUI/Textures/Draw.tga",
				     glm::vec3(-_camera.x, -_camera.y, -_camera.z),
				     FOV, _ratio, true));
  else if (winer == -1) // Game Over
    items.push_back(new Background("./BomberGUI/Textures/GameOver.tga",
				   glm::vec3(-_camera.x, -_camera.y, -_camera.z),
				   FOV, _ratio, true));
  else // winner
    {
      ss << "Joueur " << winer + 1 << " Gagne";
      items.push_back(new Background("./BomberGUI/Textures/Victory.tga",
				     glm::vec3(-_camera.x, -_camera.y, -_camera.z),
				     FOV, _ratio, true));
      items.push_back(new TextGUI(ss.str(), "./BomberGUI/Textures/Font.tga",
				  _camera, FOV / 2.0, _ratio,
				  0.20, 0.85, 0.3, 3));
    }

  ending = 7.0;
  while (ending > 0.0 && update())
    {
      drawMenu(items);
      ending -= _clock.getElapsed();
    }

  for (std::vector<AObject *>::const_iterator it = items.begin() ; it != items.end(); ++it)
    delete(*it);

  _GameManager->reset();
}
