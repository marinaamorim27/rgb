
//! @file script.hpp
#ifndef __rgb_script_hpp__
#define __rgb_script_hpp__
#include <fstream>
#include <algorithm>
#include <iostream>
#include <rgb/image.hpp>
#include <png/png.hpp>
namespace rgb {
    class script {
    private:
        void fill(); /**< applies transformations correspondents to the image using member functions correspondents of rgb::image */
        void open();  /**< initializes image of file filename */
        void blank(); /**< initializes image with w*h dimensions and initial color (r,g,b) por every pixel */
        void save();  /**< saves image to file filename */
        void invert(); /**< applies transformations correspondents to the image using member functions correspondents of rgb::image */
        void to_gray_scale(); /**< applies transformations correspondents to the image using member functions correspondents of rgb::image */
        void replace(); /**< applies transformations correspondents to the image using member functions correspondents of rgb::image */
        void crop(); /**< applies transformations correspondents to the image using member functions correspondents of rgb::image */
        void mix();   /**< applies transformations to the image as described for rgb::image, reading the image to the mix from filename, uses png::load to load an image. */
        void rotate_right(); /**< applies transformations correspondents to the image using member functions correspondents of rgb::image */
        void add(); /**< applies transformations to the image as described for rgb::image, reading the image to the addiction from filename, uses png::load to load an image. */
        void rotate_left(); /**< applies transformations correspondents to the image using member functions correspondents of rgb::image */

    public:
        script(const std::string& filename);
        ~script();  /**< deletes img */
        void process();  /**< read the command and calls the corresponding function */

    private:
        image* img; /**< image */
        std::ifstream input; /**< input */
        std::string root_path; /**< path to the file */

    };
}
#endif
