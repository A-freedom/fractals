#include <fstream>
#include <iostream>

using namespace std;
int main(){
    int max_iteration = 65;
    float r_start = -2.01,r_end = -0.985;
    float i_start = -0.81,i_end =0.003;
    int size = 5000 ;
    int width =  size*(r_end-r_start)/(i_end-i_start);
    int height =  size*(i_end-i_start)/(r_end-r_start);
    cout << "resloution : " << width << "*" << height << endl;
    cout << "ration : " << width*1.0/height << endl;

    float steps_x = (r_end-r_start)/width;
    float steps_y = (i_end-i_start)/height;

    ofstream img ("picture.ppm");
    img << "P3" << endl;
    img << width << " " << height << endl;
    img << 120 << endl;
    for(int i = 0; i < height;i++){
        for(int r = 0; r < width;r++){
            double x = 0;
            double y = 0;
            float xo = (r_end-r_start)*r/width + r_start;
            float yo = (i_end-i_start)*i/height + i_start;
            int iteration = 0;
            while (x*x + y*y <= 2*2 && iteration < max_iteration){
                    float xtemp = x*x - y*y + xo;
                     y = 2*x*y + yo;
                     x = xtemp;
                    iteration++;
            }
            img << iteration*(255/max_iteration) << " " << iteration*(255/max_iteration) << " " << iteration*(255/max_iteration) << endl;
        }
    }

    system("open picture.ppm");
    return 0;
}
