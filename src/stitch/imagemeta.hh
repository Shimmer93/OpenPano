//File: imagemeta.hh
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once
#include <string>
#include <memory>
#include "lib/mat.h"
#include "lib/imgproc.hh"
#include "match_info.hh"

namespace pano {
		struct ImageMeta {
			std::string fname;
			mutable Mat32f* img = nullptr;
			mutable int _width, _height;

			void load() const {
				if (img)
					return;
				img = new Mat32f{read_img(fname.c_str())};
				_width = img->width();
				_height = img->height();
			}

			void release() { if (img) delete img; img = nullptr; }

			int width() const { return _width; }
			int height() const { return _height; }
			Shape2D shape() const { return {_width, _height}; }

			ImageMeta(const std::string& fname): fname(fname) {}

			~ImageMeta() { if (img) delete img; }
		};

}
