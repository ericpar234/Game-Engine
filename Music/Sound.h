#ifndef EJF_SOUND
#define EJF_SOUND

#include <windows.h>
#include <Windows.h>
#include <Mmsystem.h>
#include <mciapi.h>

#include <string>
#include <iostream>

#pragma comment(lib, "winmm.lib")

class Sound
{
public:
	Sound();
	Sound(std::wstring _name, std::wstring _path);
	Sound(LPCWSTR _name, LPCWSTR _path);
	~Sound();

	void Initialize();

	void Play();
	void PlayRepeat();
	void Pause();
	void Resume();
	void Stop();



private:
	std::wstring name;
	std::wstring path;


};



#endif
