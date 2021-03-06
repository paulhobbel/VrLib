#pragma once

#include <string>

namespace vrlib
{
	class Image
	{
	public:
		int width;
		int height;
		int depth;
		unsigned char* data;
		std::string fileName;

		bool usesAlpha;

		Image(const std::string &filename, bool flip = true);
		Image(int width, int height);
		virtual ~Image();
		void unload();
		void save(const std::string &fileName);
		void scale(int w, int h);
		void flipv();

		class Col
		{
		public:
			Image* img;
			int x;
			unsigned char* operator [] (int y) { return img->data + ((x + img->width*y) * 4); }
		};

		Col operator [] (int x) { return{ this, x }; }

	};
}