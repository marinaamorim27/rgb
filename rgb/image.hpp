//! @file image.hpp
#ifndef __rgb_image_hpp__
#define __rgb_image_hpp__
#include <cassert>
#include <rgb/color.hpp>


namespace rgb {
    class image {
    private:
        int iwidth; /**< width of the image */
        int iheight; /**< height of the image */
        color **pixels; /**< pixels of the image, matrix of colors implemented like pointers array */

    public:
        image(int w, int h, const color& fill = color::WHITE);  /**< constructor of image with width w, height h and initial color fill for all pixels*/
        ~image(); /**< destructor, free allocated space for pixels matrix */
        int width() const;  /**< gets width of the image */
        int height() const; /**< gets height of the image */
        color& at(int x, int y); /**< gets mutable reference for pixel color in position (x,y) for 0≤x<width() and 0≤y<height() */
        const color& at(int x, int y) const; /**< gets constant reference for pixel color in position (x,y) for 0≤x<width() and 0≤y<height() */

        void invert(); /**< invert every pixel of the image, applying color.invert() */
        void to_gray_scale();   /**< convert every pixel to gray scale, applying color.to_gray_scale() */
        void replace(const color& a, const color& b); /**< changes the color of every pixel from a to b */
        void fill(int x, int y, int w, int h, const color& c); /**< defines color c to every pixel with coordinates (x',y') where x≤x′<x+w e y≤y′<y+h. */
        void mix(const image& img, int factor); /**< changes image, mixing each pixel with the corresponding pixel from img with factor f, applying color.mix() */
        void crop(int x, int y, int w, int h); /**< reduces the image to the rectangle wit the top right corner (x,y) and dimension w*h */
        void rotate_left(); /**< rotates image to left */
        void rotate_right(); /**< rotates image to right */
        void add(const image& img, const color& neutral, int x, int y); /**< adds the content of the img, replacing current pixels, from the position (x,y) except for pixels in img with neutral color */
    };
}


#endif
