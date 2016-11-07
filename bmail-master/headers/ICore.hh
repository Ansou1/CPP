//
// ICore.hh for lol in /home/dell-a_f//projets/suicide/headers
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Sun Mar 10 10:53:35 2013 florian dell-aiera
// Last update Sun Mar 10 10:53:49 2013 florian dell-aiera
//


#ifndef		__ICORE__
#define		__ICORE__

class		ICore
{
public:
  virtual bool	receiveMail() = 0;
  virtual bool	deleteMail() const = 0;
  virtual	~ICore() {};
};

#endif
