//! @file color.hpp
#ifndef __rgb_color_hpp__
#define __rgb_color_hpp__

#include <iostream>
#include <fstream>

namespace rgb {
    typedef unsigned char rgb_value;

    class color {
    
    private:
        rgb_value r;  /**< value r(red) of the color */
        rgb_value g; /**< value g(green) of the color */
        rgb_value b; /**< value b(blue) of the color */
        
    public:
        static const color RED;     /**< constant for color red*/
        static const color GREEN;   /**< constant for color green*/
        static const color BLUE;    /**< constant for color blue*/
        static const color BLACK;   /**< constant for color black*/
        static const color WHITE;   /**< constant for color white*/
        color();                    /**< constructor by omission, initializes all RGB constants with 0 */
        color(const color &c);      /**< constructor by copy */
        color(rgb_value r, rgb_value g, rgb_value b);  /**< constructor that uses given values for initialize RGB components */
        rgb_value red() const;    /**< gets value or reference for red component */
        rgb_value& red();
        rgb_value green() const;    /**< gets value or reference for green component */
        rgb_value& green();
        rgb_value blue() const;     /**< gets value or reference for blue component */
        rgb_value& blue();
        color& operator=(const color&c);  /**< assignment operator */
        bool operator==(const color &c) const;  /**< comparison operators */
        bool operator!=(const color &c) const;
        void invert();   /**< invert colors : (r,g,b)↦(255−r,255−g,255−b)*/
        void to_gray_scale(); /**< convert color to gray scale: (r,g,b)↦(v,v,v) where v=(r+g+b)/3 */
        void mix(const color& c, int f); /**< mix c with factor f between 0 and 100: (r,g,b)↦(m(r,c.r),m(g,c.g),m(b,c.b)) where m(a,b)=((100−f)a+fb)/100 */
    };
}
#endif
