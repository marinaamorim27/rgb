#include <rgb/color.hpp>
#include <rgb/image.hpp>
#include <rgb/script.hpp>
#include <png/png.hpp>
#include <fstream>
#include <algorithm>

namespace rgb {

    image::image(int w, int h, const color& fill) {
        iwidth=w;
        iheight=h;
        pixels =new color*[iwidth];
        color *data = new color[iwidth * iheight];
        for(int i = 0; i < iwidth; i++){
            pixels[i] = data + i * iheight;
            for (int j = 0; j < iheight; j++) {
                pixels[i][j] = fill;
            }
        }
    }
    image::~image() {
        // apagar matrix que criamos
        //for(int i = 0; i < iheight; ++i) {
        delete[] pixels[0];
        //}
        //Free the array of pointers
        delete[] pixels;
    }
    int image::width() const {
        return iwidth;
    }
    int image::height() const {
        return iheight;
    }
    color& image::at(int x, int y) {
        return pixels[x][y];
    }
    const color& image::at(int x, int y) const {
        return pixels[x][y];
    }
    void image::invert() {
        // inverte todos os pixeis da imagem, aplicando color.invert()

        for(int i=0;i<iwidth;i++){
            for(int j=0;j<iheight;j++){
                pixels[i][j].invert();
            }
        }

    }
    void image::to_gray_scale() {
        // converte todos os pixeis para uma escala de cinzento, aplicando color.to_gray_scale()

        for(int i=0;i<iwidth;i++){
            for(int j=0;j<iheight;j++){
                pixels[i][j].to_gray_scale();
            }
        }

    }
    void image::fill(int x, int y, int w, int h, const color& c) {
        // define a cor c para todos os pixeis com coordenadas (x',y')
        // tais que x<=x'< x + w   e  y <=y'< y+h

        for(int i=0;i<iwidth;i++){
            for(int j=0;j<iheight;j++){
                if(i >= x && i<x+w && j>=y && j<y+h){
                    pixels[i][j]=c;
                }
            }
        }
    }
    void image::replace(const color& a, const color& b) {
        for(int i=0;i<iwidth;i++){
            for(int j=0;j<iheight;j++){
                if(pixels[i][j]==a){
                    pixels[i][j]=b;
                }
            }
        }
        // altera a cor de todos os pixeis com cor a para a cor b
    }
    void image::add(const image& img, const color& neutral, int x, int y) {
        for(int i=x;i<iwidth;i++){
            for(int j=y;j<iheight;j++){
                if((i-x)<img.iwidth && (j-y)<img.iheight){
                    if(color(img.pixels[i-x][j-y])!=(color(neutral))){
                        pixels[i][j]=img.pixels[i-x][j-y];

                    }

                }
            }
        }
    }

    void image::crop(int x, int y, int w, int h) {
        //Reduz a imagem (alterando sua dimensão) ao rectângulo com o topo superior esquerdo (x,y) e dimensão w × h.
        color **auxiliar1;
        auxiliar1 = new color *[w];
        color *data = new color[w * h];
        for (int i = 0; i < w; i++) {
            auxiliar1[i] = &data[i * h];
        }
        //Copia valores e redefinir campos
        int k = 0;
        int l;
        for (int i = x; i < (x+w); i++) {
            l = 0;
            for (int j = y; j < (y+h); j++) {
                auxiliar1[k][l] = pixels[i][j] ;
                l++;
            }
            k++;
        }
        iwidth = w;
        iheight = h;
        //Liberta espaço anterior
        delete [] pixels[0];
        delete [] pixels;
        pixels = auxiliar1;
    }


    void image::rotate_left() {
        color** ipixels = new color*[iheight] ;
        color *data = new color[iwidth * iheight];
        for(int i = 0; i < iheight; i++){
            ipixels[i] = &data[i * iwidth];
        }

          int m;
          for(int j = 0; j < iheight ; j++){
            m=0;
            for(int i= iwidth-1; i >= 0; i--){
                ipixels[j][m]=pixels[i][j];
                m++;
            }
          }

        int tmp = iheight;
        iheight = iwidth;
        iwidth = tmp;
        delete [] pixels[0];
        delete [] pixels;
        pixels = ipixels;
    }

    void image::rotate_right() {
        color** ipixels = new color*[iheight] ;
        color *data = new color[iwidth * iheight];
        for(int i = 0; i < iheight; i++){
            ipixels[i] = &data[i * iwidth];
        }

          int m=0;
          for(int j = iheight -1; j >=0; j--){
            for(int i=0; i < iwidth; i++){
                ipixels[m][i]=pixels[i][j];
            }
            m++;
          }

        int tmp = iheight;
        iheight = iwidth;
        iwidth = tmp;
        delete [] pixels[0];
        delete [] pixels;
        pixels = ipixels;
    }


      void image::mix(const image& img, int factor) {
        for(int i=0;i<iwidth;i++){
            for(int j=0;j<iheight;j++){
                pixels[i][j].mix(img.pixels[i][j],factor);
            }
        }

        // altera imagem, misturando cada pixel com o pixel correspondete em img com factor f aplicando
        // color.mix()
     }

}
