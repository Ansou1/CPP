#include "BombManager.hh"

BombManager::BombManager()
{
  _range = 2;
  _nbBombMax = 1;
  _nbBomb = 1;
  _hasDrop = false;
}

BombManager::~BombManager()
{
}

bool			BombManager::canDropBomb() const
{
  return (_nbBomb > 0);
}

void			BombManager::dropBomb()
{
  _hasDrop = false;
  _nbBomb--;
}

void			BombManager::reload()
{
  _nbBomb++;
}

size_t			BombManager::getRange() const
{
  return (_range);
}

bool			BombManager::hasDropBomb() const
{
  return (_hasDrop);
}
