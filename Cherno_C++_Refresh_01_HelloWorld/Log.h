#pragma once //prevents a sinle header file from being included multiple times in same translation unit
				//works when this header included in another header and both headers included in .cpp file
			//alternate to pragma once is #ifndef LOG_H #def LOG_H
void InitLog();
void Log(const char* message);