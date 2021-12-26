#include <fstream>
#include <algorithm>
#include <iostream>


#include <rgb/script.hpp>
#include <png/png.hpp>
#include <rgb/image.hpp>
#include <rgb/color.hpp>

namespace rgb {
    std::istream& operator>>(std::istream& input, color& c) {
        int r,g,b;
        input >> r >> g >> b;
        c.red() = r;
        c.green() = g;
        c.blue() = b;
        return input;
    }
    script::script(const std::string& filename) :
            img(NULL), input(filename), root_path(ROOT_PROJ_DIR) {

    }
    script::~script() {
        if (img != NULL) {
            delete img;
        }
    }

    void script::process() {
        while (!input.eof()) {
            std::string command;
            input >> command;
            if (command.empty()) {
                break;
            }
            std::cout << "Executing command '" << command << "' ..." << std::endl;

            if (command == "open") {
                open();
            }
            else if (command == "blank") {
                blank();
            }

            // Other commands
            if (img == NULL) {
                std::cout << "No image loaded! Stopping ..." << std::endl;
                break;
            }

            if (command == "save") {
                save();
            } else if (command == "fill") {
                fill();
            } else if (command == "to_gray_scale") {
                to_gray_scale();
            } else if (command == "invert"){
                img->invert();
            } else if(command =="replace"){
                replace();
            }
             else if (command == "mix"){
                mix();
            } else if(command=="crop"){
                 crop();
             }else if(command=="add"){
                add();
            }
            else if (command == "rotate_right") {
                rotate_right();
            } else if (command == "rotate_left"){
                 rotate_left();
             }

        }
    }
    void script::open() {
        if (img != NULL) {
            // Delete previous image
            delete img;
        }
        std::string filename;
        input >> filename;
        img = png::load(root_path + "/" + filename);
    }
    void script::blank() {
        if (img != NULL) {
            // Delete previous image
            delete img;
        }
        int w, h;
        color c;
        input >> w >> h >> c;
        img = new image(w, h, c);
    }
    void script::save() {
        std::string filename;
        input >> filename;
        png::save(root_path + "/" + filename, img);
    }
    void script::mix() {
        int fator;
        std::string file;
        input >> file;
        image* imagem = png::load(root_path + "/" + file);
        input >> fator;
        img->mix(*imagem, fator);
    }
    void script::fill() {
        int x, y, w, h;
        color c;
        input >> x >> y >> w >> h >> c;
        img -> fill(x, y, w, h, c);
    }
    void script::replace() {
        color a;
        color b;
        input >> a >> b;
        img -> replace(a,b);
    }
    void script::add() {
        std::string file;
        input >> file;
        image* imagem = png::load(root_path + "/" + file);
        color neutro;
        int x, y;
        input >> neutro >> x >> y;
        img->add(*imagem, neutro, x, y);
    }

    void script::invert() {
        img ->invert();
    }
    void script::crop() {
        int x, y, w, h;
        input >> x >> y >> w >> h;
        img -> crop(x, y, w, h);
    }

     void script::rotate_right(){
         img ->rotate_right();
     }
    void script::to_gray_scale(){
        img -> to_gray_scale();
    }
    void script::rotate_left() {
        img -> rotate_left();
    }

}

