/*
 * dmObj.hpp
 *
 *  Created on: Jan 24, 2012
 *      Author: Tofs
 */

#ifndef OBJ_HPP_
#define OBJ_HPP_


#include <algorithm>
#include <vector>
#include <list>
#include <EGL/egl.h>
#include <GLES/gl.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream.h>
#include <sstream>

namespace ttit
{


	class obj
	{
	private:

		GLuint verticessize;
		GLfloat *vertices;
		GLuint normalsize;
		GLfloat *normals;
		GLuint vindexsize;
		GLushort *vindex;
		GLuint nindexsize;
		GLushort *nindex;
		bool init;
	public:
		obj();
		void dumpInfo();
		int readObjFile(std::string path);
		void render();
	};

}

#endif /* OBJ_HPP_ */

