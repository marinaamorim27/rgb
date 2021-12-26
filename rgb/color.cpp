#include <rgb/color.hpp>
#include <rgb/image.hpp>
#include <rgb/script.hpp>
#include <png/png.hpp>
#include <fstream>
#include <algorithm>
#include <iostream>


namespace rgb {
    const color color::BLACK(0,0,0);
    const color color::WHITE(255,255,255);
    const color color::RED(255,0,0);
    const color color::GREEN(0,255,0);
    const color color::BLUE(0,0,255);


    // default constructor
    color::color() {
        r=0;
        g=0;
        b=0;
    }

    // parameterized constructor
    color::color(rgb_value red, rgb_value green, rgb_value blue) {
        r=red;
        g=green;
        b=blue;
    }

    // parameterized constructor
    color::color(const color& other) {
        r=other.r;
        g=other.g;
        b=other.b;
    }


    rgb_value color::red() const {
        return r;
    }

    rgb_value color::green() const {
        return g;
    }

    rgb_value color::blue() const {
        return b;
    }

    rgb_value& color::red()  {
        return r;
    }

    rgb_value& color::green()  {
        return g;
    }

    rgb_value& color::blue()  {
        return b;
    }

    color& color::operator=(const color& c) {
        r=c.r;
        g=c.g;
        b=c.b;
        return *this;
    }

    bool color::operator==(const color &c) const {
        return (r==c.r && g==c.g && b==c.b);
    }

    bool color::operator!=(const color &c) const {
        return !(r==c.r && g==c.g && b==c.b);
    }

    void color::invert() {
        // inverte cor (r,g,b)-> (255-r,255-g,255-b)
        r=255-r;
        g=255-g;
        b=255-b;
    }

    void color::mix(const color& c, int f) {
        //Mistura com cor c com um factor f entre 0 e 100: (r,g,b)↦(m(r,c.r),m(g,c.g),m(b,c.b)) onde m(a,b)=((100−f)a+fb)/100.
        r=(r*(100-f)+f*(c.r))/100;
        g=(g*(100-f)+f*(c.g))/100;
        b=(b*(100-f)+f*(c.b))/100;
    }

    void color::to_gray_scale() {
        // converte cor para uma escala de cinzento
        // (r,g,b) -> (v,v,v) onde v = (r+g+b)/3
        int v=(r + g + b)/3;
        r = v;
        g = v;
        b = v;
    }
}