#pragma once
#include "irrKlang.h"
#include "ik_ISoundEngine.h"
#include "Vector.h"

namespace Aftr {
	class SoundManager {

	protected:
		irrklang::ISoundEngine* engine = nullptr;
		std::vector<irrklang::ISound*> sound2D;
		std::vector<irrklang::ISound*> sound3D;

	public:
		static SoundManager* init();
		virtual void play2DSound(const char* fileName, bool looped, bool paused, bool track);
		virtual void play3DSound(const char* fileName, Aftr::Vector position, bool playLooped, bool paused, bool track);
		virtual void stop2DSound();
		virtual void stop3DSound();
		virtual irrklang::vec3df convertFromVector(Vector position);
		virtual irrklang::ISoundEngine* getSoundEngine();
		virtual void setSoundEngine(irrklang::ISoundEngine* soundEngine);
		virtual std::vector<irrklang::ISound*> get2DSound();
		virtual std::vector<irrklang::ISound*> get3DSound();
	};
}