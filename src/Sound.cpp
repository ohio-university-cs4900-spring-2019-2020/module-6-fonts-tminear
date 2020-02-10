#include "Sound.h"

using namespace Aftr;
using namespace std;

SoundManager* SoundManager::init() {
	SoundManager* sound = new SoundManager();
	irrklang::ISoundEngine* tempEngine = irrklang::createIrrKlangDevice();

	if (tempEngine == NULL) {
		cout << "Cannot create Sound Engine" << endl;
	}
	sound->setSoundEngine(tempEngine);

	return sound;
}

void SoundManager::play2DSound(const char* fileName, bool looped, bool paused, bool track) {
	if (!this->engine)
		return;

	this->sound2D.push_back(this->engine->play2D(fileName, looped, paused, track));
}

void SoundManager::play3DSound(const char* fileName, Aftr::Vector position, bool playLooped, bool paused, bool track) {
	if (!this->engine)
		return;

	this->sound3D.push_back(this->engine->play3D(fileName, this->convertFromVector(position), playLooped, paused, track));
}

void SoundManager::stop2DSound() {
	if (sound2D.empty()) {
		return;
	}

	sound2D.at(0)->stop();
	sound2D.erase(sound2D.begin());
}

void SoundManager::stop3DSound() {
	if (sound3D.empty()) {
		return;
	}

	sound3D.at(0)->stop();
	sound3D.erase(sound3D.begin());
}

irrklang::vec3df SoundManager::convertFromVector(Vector position) {
	return irrklang::vec3df(position.x, position.y, position.z);
}

irrklang::ISoundEngine* SoundManager::getSoundEngine() {
	return this->engine;
}

void SoundManager::setSoundEngine(irrklang::ISoundEngine* soundEngine) {
	this->engine = soundEngine;
}

std::vector<irrklang::ISound*> SoundManager::get2DSound() {
	return this->sound2D;
}

std::vector<irrklang::ISound*> SoundManager::get3DSound() {
	return this->sound3D;
}
