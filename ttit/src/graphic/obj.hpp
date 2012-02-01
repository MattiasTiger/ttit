/*
 * dmObj.hpp
 *
 *  Created on: Jan 24, 2012
 *      Author: Tofs
 */

#ifndef OBJ_HPP_
#define OBJ_HPP_


#include <list>
#include <EGL/egl.h>
#include <GLES/gl.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream.h>

namespace ttit
{


	class obj
	{
	private:

		GLuint verticessize;
		GLfloat *vertices;
		GLuint indexsize;
		GLushort *index;
		bool init;
	public:
		obj();
		void dumpInfo();
		int readObjFileOld(std::string path);
		int readObjFile(std::string path);
		void render();
	};

}

#endif /* OBJ_HPP_ */

