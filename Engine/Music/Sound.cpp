#include "Sound.h"

Sound::Sound()
{
}

Sound::Sound(std::wstring _name, std::wstring _path)
{
	name = _name;
	path = _path;
	name = _name;
	Initialize();
}

Sound::Sound(LPCWSTR _name, LPCWSTR _path)
{
	std::wstring n(_name);
	name = n.c_str();

	std::wstring p(_path);
	path = p.c_str();
	Initialize();
}

Sound::~Sound()
{
	std::wstring concatted_stdstr = L"close " + name;
	LPCWSTR cmd = concatted_stdstr.c_str();
	mciSendString(cmd, NULL, 0, NULL);
}

void Sound::Initialize()
{
	std::wstring concatted_stdstr = L"open \"" + path + L"\" type mpegvideo alias " + name;
	LPCWSTR cmd = concatted_stdstr.c_str();
	mciSendString(cmd, NULL, 0, NULL);
}

void Sound::Play()
{
	std::wstring concatted_stdstr = L"play " + name + L" from 0";
	mciSendString(concatted_stdstr.c_str(), NULL, 0, NULL);

}

void Sound::PlayRepeat()
{
	std::wstring concatted_stdstr = L"play " + name + L" repeat from 0";
	LPCWSTR cmd = concatted_stdstr.c_str();
	mciSendString(cmd, NULL, 0, NULL);
}

void Sound::Pause()
{
	std::wstring concatted_stdstr = L"pause " + name;
	LPCWSTR cmd = concatted_stdstr.c_str();
	mciSendString(cmd, NULL, 0, NULL);
}

void Sound::Resume()
{
	std::wstring concatted_stdstr = L"resume " + name;
	LPCWSTR cmd = concatted_stdstr.c_str();
	mciSendString(cmd, NULL, 0, NULL);
}

void Sound::Stop()
{
	std::wstring concatted_stdstr = L"stop " + name;
	LPCWSTR cmd = concatted_stdstr.c_str();
	mciSendString(cmd, NULL, 0, NULL);
}
