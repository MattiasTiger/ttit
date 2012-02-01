/*
 * dmObj.cpp
 *
 *  Created on: Jan 24, 2012
 *      Author: Tofs
 */

#include "obj.hpp"

namespace ttit
{

obj::obj()
{
	init = false;
}

void obj::dumpInfo()
{

}

int obj::readObjFile(std::string path)
{
	init = true;

	std::ifstream fileStream(path.c_str(), ifstream::in);

	std::list<GLfloat> vList;
	std::list<GLuint> iList;

	GLfloat x, y, z;
	GLuint n1, n2, n3, v1, v2, v3;

	std::string line;

	while(!fileStream.eof())
	{
		getline(fileStream, line);
		std::cout << "this is a line: " << line << std::endl;
	}

	return 0;
}

int obj::readObjFileOld(std::string path)
{
	init = true;

	//open file as binary
	FILE *fp = fopen(path.c_str(), "rb");
	fprintf(stderr, "File read, success=%i", (int)fp);

	std::list<GLfloat> vList;
	std::list<GLuint> iList;
	GLfloat x, y, z;
	GLuint n1, n2, n3, v1, v2, v3;
	char buff[200];
	while(fscanf(fp, "%s", buff) != EOF)
	{


		if (buff[0] == 'g')
		{
		}
		else if (buff[0] == 'v' && buff[1] == 'n')
		{
		}
		else if(buff[0] == 'v')
		{
			fscanf(fp, "%f %f %f", &x, &y, &z);
			fprintf(stderr, "vertise: %f %f %f\n", x, y, z);
			vList.push_back(x);
			vList.push_back(y);
			vList.push_back(z);
			vList.push_back(1.0f);

		}
		else if (buff[0] == 'f')
		{

			fscanf(fp, "%u %u %u %u %u %u", &v1, &n1, &v2, &n2, &v3, &n3);
			fprintf(stderr, "face: %u %u %u \n", v1, v2, v3);
			iList.push_back(v1);
			iList.push_back(v2);
			iList.push_back(v3);

		}

	}

	if (!fp)
	{
		return -1;
	}

	verticessize = vList.size();
	vertices = new GLfloat[verticessize];
	for (GLuint i = 0; i < verticessize; i++)
	{

		vertices[i] = vList.front();
		fprintf(stderr, "%f\n", vList.front());
		vList.pop_front();
	}


	indexsize = iList.size();
	index = new GLushort[indexsize];
	for (GLuint i = 0; i < indexsize; i++)
	{
		index[i] = iList.front();
		fprintf(stderr, "%u\n", index[i]);
		iList.pop_front();
	}

	fprintf(stderr, "done\n: %i %i", verticessize, indexsize);
	fclose(fp);

	return 0;
}

void obj::render()
{

	/*

	glRotatef(1.0f, 1.0f, 1.0f, 0.0f);
	glVertexPointer(4, GL_FLOAT, 0, vertices);
	glDrawElements(GL_TRIANGLES, indexsize, GL_UNSIGNED_SHORT ,index);

	*/
}
}

