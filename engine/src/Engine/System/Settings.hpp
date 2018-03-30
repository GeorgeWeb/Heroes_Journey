#ifndef SETTINGS
#define SETTINGS

#include <SFML/Graphics.hpp>

namespace Engine { namespace System {

	enum SCREEN_MODE
	{
		WINDOWED   = 0,
		FULLSCREEN = 1
	};

	class Settings final
	{
		public:
			Settings() = default;
			~Settings() = default;

			void Save();

			inline SCREEN_MODE GetScreenMode() const { return m_screenMode; };
			void SetScreenMode(const SCREEN_MODE& t_mode);

			inline bool HasVSync() const { return m_hasVsync; }
			void SetVSyncOn(bool t_vsync);

			void SetResolution(unsigned int t_width, unsigned int t_height);

		private:
			void SaveScreenOpts();

		private:
			// decision handlers
			bool m_hasVsync;
			// resolution dimensions
			unsigned int m_screenWidth;
			unsigned int m_screenHeight;
			// screen mode option
			SCREEN_MODE m_screenMode;
	};

} }

#endif // !SETTINGS
 